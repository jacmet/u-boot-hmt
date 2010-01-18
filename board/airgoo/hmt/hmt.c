/* (C) Copyright 2009 Peter Korsgaard <jacmet@sunsite.dk>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <s3c6400.h>
#include <i2c.h>
#include <asm/io.h>

#define MAX8698_ONOFF1	0
#define MAX8698_ONOFF2	1
#define MAX8698_LDO9	14

static int max8698_write(unsigned char reg, unsigned char val)
{
	return i2c_write(0x66, reg, 1, &val, 1);
}

int board_init(void)
{
	DECLARE_GLOBAL_DATA_PTR;

	gd->bd->bi_arch_number = MACH_TYPE;
	gd->bd->bi_boot_params = PHYS_SDRAM_1 + 0x100;

	return 0;
}

int dram_init(void)
{
	DECLARE_GLOBAL_DATA_PTR;

	gd->bd->bi_dram[0].start = PHYS_SDRAM_1;
	gd->bd->bi_dram[0].size = PHYS_SDRAM_1_SIZE;

	return 0;
}

int misc_init_r(void)
{
	max8698_write(MAX8698_ONOFF1, 0x3e); /* enable LDO3+4 */
	max8698_write(MAX8698_ONOFF2, 0xf1); /* enable LDO7+8 */
	max8698_write(MAX8698_LDO9, 0x11); /* LDO9 = 3.3V */

	writel(0,0x7410800c); /* panel */
	writel(0x1801e, 0x7e00f900); /* usb */

	writel(0x22221122, 0x7f008000); /* gpa */
	writel(0xff, 0x7f008004);
	writel(0xa0, 0x7f008008);

	writel(0x02211122, 0x7f008020); /* gpb */
	writel(0x2800, 0x7f008028);
	writel(0x2802, 0x7f00802c);

	writel(0x11112222, 0x7f008040); /* gpc */
	writel(0x0d, 0x7f008044);

	writel(0x00044474, 0x7f008060); /* gpd */
	writel(0x03, 0x7f008064);
	writel(0x02aa, 0x7f00806c);

	writel(0x00011111, 0x7f008080); /* gpe */

	writel(0xb6aaaa6a, 0x7f0080a0); /* gpf */
	writel(0x6ffe, 0x7f0080a4);
	writel(0x08000000, 0x7f0080a8);
	writel(0x2aaaaaaa, 0x7f0080ac);

	writel(0x01222222, 0x7f0080c0); /* gpg */

	writel(0x11222222, 0x7f0080e0); /* gph */
	writel(0x00000011, 0x7f0080e4);
	writel(0x3e, 0x7f0080e8);

	writel(0xaaaaaaaa, 0x7f008100); /* gpi */

	writel(0x00aaaaaa, 0x7f008120); /* gpj */

	writel(0x11111111, 0x7f008800); /* gpk */
	writel(0x11100000, 0x7f008804);
	writel(0x00001f80, 0x7f008808);
	writel(0x00008000, 0x7f00880c);

	writel(0x11100011, 0x7f008810); /* gpl */
	writel(0x00100100, 0x7f008814);
	writel(0x00004318, 0x7f008818);
	writel(0x05, 0x7f00881c);

	writel(0x00111111, 0x7f008820); /* gpm */

	writel(0x20a00006, 0x7f008830); /* gpn */
	writel(0x0000cdfb, 0x7f008834);
	writel(0x00000006, 0x7f008838);

	writel(0x55555555, 0x7f008140); /* gpo */
	writel(0x00008000, 0x7f008144);

	writel(0x1555aaa5, 0x7f008160); /* gpp */
	writel(0x000000e4, 0x7f008164);

	writel(0x00015555, 0x7f008180); /* gpq */

	writel(0xbfcd1501, 0x7f0081a0); /* spcon */

	writel(0x00, 0x7c100000); /* USB OTG */
	writel(0x20, 0x7c100004);
	writel(0x00, 0x7c100008);

	return 0;
}
