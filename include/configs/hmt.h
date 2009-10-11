/* (C) Copyright 2009 Peter Korsgaard <jacmet@sunsite.dk>
 *
 * Configuation settings for the Airgoo HMT board.
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

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * High Level Configuration Options
 * (easy to change)
 */
#define CONFIG_S3C6410		1	/* in a SAMSUNG S3C6410 SoC     */
#define CONFIG_S3C64XX		1	/* in a SAMSUNG S3C64XX Family  */
#define CONFIG_HMT		1	/* on a Airgoo HMT Board        */

#define CONFIG_SYS_SDRAM_BASE	0x50000000

/* input clock of PLL: SMDK6400 has 12MHz input clock */
#define CONFIG_SYS_CLK_FREQ	12000000

#define CONFIG_MEMORY_UPPER_CODE

#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_CMDLINE_TAG
#define CONFIG_INITRD_TAG

/*
 * Architecture magic and machine type
 */
#define MACH_TYPE		2254

#define CONFIG_DISPLAY_CPUINFO

#undef CONFIG_SKIP_RELOCATE_UBOOT

/*
 * Size of malloc() pool
 */
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + 1024 * 1024)
#define CONFIG_SYS_GBL_DATA_SIZE	128	/* size in bytes for initial data */

/*
 * select serial console configuration
 */

#define CONFIG_SERIAL3          1	/* we use SERIAL 3 on SMDK6400	*/

#define CONFIG_SYS_HUSH_PARSER			/* use "hush" command parser	*/
#ifdef CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_PROMPT_HUSH_PS2	"> "
#endif

#define CONFIG_CMDLINE_EDITING

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE

#define CONFIG_BAUDRATE		115200

/***********************************************************
 * Command definition
 ***********************************************************/
//#define MINIMAL
#ifndef MINIMAL
#include <config_cmd_default.h>

#define CONFIG_CMD_CACHE
#define CONFIG_CMD_REGINFO
#undef CONFIG_CMD_LOADS
#undef CONFIG_CMD_FPGA
#undef CONFIG_CMD_NET
#undef CONFIG_CMD_NFS
#undef CONFIG_CMD_SETGETDCR
#undef CONFIG_CMD_XIMG
#define CONFIG_CMD_LOADB
#define CONFIG_CMD_SAVEENV
#define CONFIG_CMD_NAND

#endif

#undef CONFIG_CMD_IMLS
#undef CONFIG_CMD_NET

#define CONFIG_BOOTDELAY	3

#define CONFIG_ZERO_BOOTDELAY_CHECK

#if (CONFIG_COMMANDS & CONFIG_CMD_KGDB)
#define CONFIG_KGDB_BAUDRATE	115200	/* speed to run kgdb serial port */
#define CONFIG_KGDB_SER_INDEX	1	/* which serial port to use	 */
#endif

/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_LONGHELP				/* undef to save memory	      */
#define CONFIG_SYS_PROMPT		"hmt> "	/* Monitor Command Prompt     */
#define CONFIG_SYS_CBSIZE		256		/* Console I/O Buffer Size    */
#define CONFIG_SYS_PBSIZE		384		/* Print Buffer Size          */
#define CONFIG_SYS_MAXARGS		16		/* max number of command args */
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE	/* Boot Argument Buffer Size  */

#define CONFIG_SYS_MEMTEST_START	CONFIG_SYS_SDRAM_BASE	/* memtest works on	      */
#define CONFIG_SYS_MEMTEST_END		(CONFIG_SYS_SDRAM_BASE + 0x7e00000) /* 126MB in DRAM */

#define CONFIG_SYS_LOAD_ADDR		CONFIG_SYS_SDRAM_BASE	/* default load address	*/

#define CONFIG_SYS_HZ			1000

/* valid baudrates */
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

/*-----------------------------------------------------------------------
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */
#define CONFIG_STACKSIZE	0x40000		/* regular stack 256KB */

/**********************************
 Support Clock Settings
 **********************************
 Setting	SYNC	ASYNC
 ----------------------------------
 667_133_66	 X	  O
 533_133_66	 O	  O
 400_133_66	 X	  O
 400_100_50	 O	  O
 **********************************/

#define CONFIG_CLK_667_133_66
//#define CONFIG_CLK_533_133_66
/*
#define CONFIG_CLK_400_100_50
#define CONFIG_CLK_400_133_66
#define CONFIG_SYNC_MODE
*/

#define CONFIG_NR_DRAM_BANKS	1
#define PHYS_SDRAM_1		CONFIG_SYS_SDRAM_BASE	/* SDRAM Bank #1	*/
#define PHYS_SDRAM_1_SIZE	0x10000000	/* 128 MB in Bank #1	*/

/* #define CONFIG_SYS_FLASH_BASE		0x10000000 */
/* #define CONFIG_SYS_MONITOR_BASE	0x00000000 */

#define CONFIG_SYS_NO_FLASH


/*
 * board specific data
 */

/* base address for uboot */
#define CONFIG_SYS_PHY_UBOOT_BASE	(CONFIG_SYS_SDRAM_BASE + 0x07e00000)
/* total memory available to uboot */
#define CONFIG_SYS_UBOOT_SIZE		(1024 * 1024)

#define CONFIG_SYS_MAPPED_RAM_BASE	CONFIG_SYS_SDRAM_BASE
#define CONFIG_BOOTCOMMAND	"nand read 0x50018000 0x60000 0x1c0000;"

/* NAND U-Boot load and start address */
#define CONFIG_SYS_UBOOT_BASE		(CONFIG_SYS_MAPPED_RAM_BASE + 0x07e00000)

#define CONFIG_ENV_OFFSET		0x00080000
#define CONFIG_ENV_OFFSET_REDUND	0x000c0000
#define CONFIG_ENV_SIZE			0x00020000	/* Total Size of Environment Sector */
#define CONFIG_ENV_SIZE_REDUND		CONFIG_ENV_SIZE

/* NAND configuration */
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define CONFIG_SYS_NAND_BASE		0x70200010
//#define CONFIG_SYS_S3C_NAND_HWECC

#define CONFIG_SYS_NAND_SKIP_BAD_DOT_I	1  /* ".i" read skips bad blocks	      */
#define CONFIG_SYS_NAND_WP		1
/* #define CONFIG_SYS_NAND_YAFFS_WRITE	1  /\* support yaffs write		      *\/ */
#define CONFIG_SYS_NAND_BBT_2NDPAGE	1  /* bad-block markers in 1st and 2nd pages  */

#define CONFIG_SYS_NAND_U_BOOT_DST	CONFIG_SYS_PHY_UBOOT_BASE	/* NUB load-addr      */
#define CONFIG_SYS_NAND_U_BOOT_START	CONFIG_SYS_NAND_U_BOOT_DST	/* NUB start-addr     */

#define CONFIG_SYS_NAND_U_BOOT_OFFS	(8192)	/* Offset to RAM U-Boot image */
#define CONFIG_SYS_NAND_U_BOOT_SIZE	(248 * 1024)	/* Size of RAM U-Boot image   */

/* NAND chip page size		*/
#define CONFIG_SYS_NAND_PAGE_SIZE	2048
/* NAND chip block size		*/
#define CONFIG_SYS_NAND_BLOCK_SIZE	(128 * 1024)
/* NAND chip page per block count  */
#define CONFIG_SYS_NAND_PAGE_COUNT	64
/* Location of the bad-block label */
#define CONFIG_SYS_NAND_BAD_BLOCK_POS	0
/* Extra address cycle for > 128MiB */
#define CONFIG_SYS_NAND_5_ADDR_CYCLE

/* Size of the block protected by one OOB (Spare Area in Samsung terminology) */
#define CONFIG_SYS_NAND_ECCSIZE	2048
/* Number of ECC bytes per OOB - S3C6400 calculates 4 bytes ECC in 1-bit mode */
#define CONFIG_SYS_NAND_ECCBYTES	3
/* Number of ECC-blocks per NAND page */
#define CONFIG_SYS_NAND_ECCSTEPS	1
/* Size of a single OOB region */
#define CONFIG_SYS_NAND_OOBSIZE	64
/* Number of ECC bytes per page */
#define CONFIG_SYS_NAND_ECCTOTAL	(CONFIG_SYS_NAND_ECCBYTES * CONFIG_SYS_NAND_ECCSTEPS)
/* ECC byte positions */
#define CONFIG_SYS_NAND_ECCPOS		{40, 41, 42, 43, 44, 45, 46, 47, \
				 48, 49, 50, 51, 52, 53, 54, 55, \
				 56, 57, 58, 59, 60, 61, 62, 63}

/* Boot configuration (define only one of next 3) */
#define CONFIG_BOOT_NAND
#define CONFIG_NAND
#define CONFIG_NAND_S3C64XX

/* Settings as above boot configuration */
#define CONFIG_ENV_IS_IN_NAND
#define CONFIG_BOOTARGS		"console=ttySAC2,115200 console=tty root=/dev/mtdblock4"

#define CONFIG_HARD_I2C				/* I2C with hardware support */
#undef CONFIG_SOFT_I2C				/* I2C bit-banged */
#define CONFIG_HARD_I2C			/* I2C with hardware support */
#define CONFIG_SYS_I2C_SPEED		100000	/* I2C speed */
#define CONFIG_SYS_I2C_SLAVE		0x7F	/* I2C slave addr */
#define CONFIG_I2C_CMD_TREE
#define CONFIG_DRIVER_S3C24X0_I2C	1	/* we use the builtin I2C controller */

#define CONFIG_CMD_I2C

#endif	/* __CONFIG_H */
