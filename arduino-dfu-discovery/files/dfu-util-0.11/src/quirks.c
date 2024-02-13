/*
 *  Simple quirk system for dfu-util
 *
 *  Copyright 2010-2017 Tormod Volden
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "portable.h"
#include "quirks.h"
#include "dfuse_mem.h"

uint16_t get_quirks(uint16_t vendor, uint16_t product, uint16_t bcdDevice)
{
	uint16_t quirks = 0;

	/* Device returns bogus bwPollTimeout values */
	if ((vendor == VENDOR_OPENMOKO || vendor == VENDOR_FIC) &&
	    product >= PRODUCT_FREERUNNER_FIRST &&
	    product <= PRODUCT_FREERUNNER_LAST)
		quirks |= QUIRK_POLLTIMEOUT;

	if (vendor == VENDOR_VOTI &&
	    (product == PRODUCT_OPENPCD || product == PRODUCT_SIMTRACE ||
	     product == PRODUCT_OPENPICC))
		quirks |= QUIRK_POLLTIMEOUT;

	/* Reports wrong DFU version in DFU descriptor */
	if (vendor == VENDOR_LEAFLABS &&
	    product == PRODUCT_MAPLE3 &&
	    bcdDevice == 0x0200)
		quirks |= QUIRK_FORCE_DFU11;

	/* old devices(bcdDevice == 0) return bogus bwPollTimeout values */
	if (vendor == VENDOR_SIEMENS &&
	    (product == PRODUCT_PXM40 || product == PRODUCT_PXM50) &&
	    bcdDevice == 0)
		quirks |= QUIRK_POLLTIMEOUT;

	/* M-Audio Transit returns bogus bwPollTimeout values */
	if (vendor == VENDOR_MIDIMAN &&
	    product == PRODUCT_TRANSIT)
		quirks |= QUIRK_POLLTIMEOUT;

	/* Some GigaDevice GD32 devices have improperly-encoded serial numbers
	 * and bad DfuSe descriptors which we use serial number to correct.
	 * They also "leave" without a DFU_GETSTATUS request */
	if (vendor == VENDOR_GIGADEVICE &&
	    product == PRODUCT_GD32) {
		quirks |= QUIRK_UTF8_SERIAL;
		quirks |= QUIRK_DFUSE_LAYOUT;
		quirks |= QUIRK_DFUSE_LEAVE;
	}

	return (quirks);
}

#define GD32VF103_FLASH_BASE 0x08000000

void fixup_dfuse_layout(struct dfu_if *dif, struct memsegment **segment_list)
{
	if (dif->vendor == VENDOR_GIGADEVICE &&
	    dif->product == PRODUCT_GD32 &&
	    dif->altsetting == 0 &&
	    dif->serial_name &&
	    strlen(dif->serial_name) == 4 &&
	    dif->serial_name[0] == '3' &&
	    dif->serial_name[3] == 'J') {
		struct memsegment *seg;
		int count;

		printf("Found GD32VF103, which reports a bad page size and "
		       "count for its internal memory.\n");

		seg = find_segment(*segment_list, GD32VF103_FLASH_BASE);
		if (!seg) {
			warnx("Could not fix GD32VF103 layout because there "
			      "is no segment at 0x%08x", GD32VF103_FLASH_BASE);
			return;
		}

		/* All GD32VF103 have this page size, according to Nucleisys's
		 * dfu-util (https://github.com/riscv-mcu/gd32-dfu-utils/). */
		seg->pagesize = 1024;

		/* From Tables 2-1 and 2-2 ("devices features and peripheral
		 * list") in the GD32VF103 Datasheet */
		if (dif->serial_name[2] == 'B') {
			count = 128;
		} else if (dif->serial_name[2] == '8') {
			count = 64;
		} else if (dif->serial_name[2] == '6') {
			count = 32;
		} else if (dif->serial_name[2] == '4') {
			count = 16;
		} else {
			warnx("Unknown flash size '%c' in part number; "
			      "defaulting to 128KB.", dif->serial_name[2]);
			count = 128;
		}

		seg->end = seg->start + (count * seg->pagesize) - 1;

		printf("Fixed layout based on part number: page size %d, "
		       "count %d.\n", seg->pagesize, count);
	}
}
