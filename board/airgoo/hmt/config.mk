# (C) Copyright 2009 Peter Korsgaard <jacmet@sunsite.dk>

ifndef CONFIG_NAND_SPL
TEXT_BASE = 0x57e00000
else
TEXT_BASE = 0
endif
