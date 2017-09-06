# $NetBSD: Makefile,v 1.3 2014/09/05 02:41:03 makoto Exp $

DISTNAME=		uhd-3.6.0
CATEGORIES=		ham

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://code.ettus.com/redmine/ettus/projects/uhd/wiki
COMMENT=		USRP (Universal Software Radio Peripheral) Hardware Drivers
LICENSE=		gnu-gpl-v2

GIT_REPOSITORIES=       master
GIT_REPO.master=        git://github.com/EttusResearch/uhd.git
GIT_MODULE.master=      uhd

USE_LANGUAGES=		c c++
USE_TOOLS=		cmake

# Please note DISTribution has many stuff under uhd/, but build itself
# needs under host/ only. Others will be installed separately.
WRKSRC=			${WRKDIR}/uhd/host

REPLACE_PYTHON=	\
        uhd-firmware/x300/bin_to_coe.py \
	utils/uhd_images_downloader.py.in \
	utils/usrp2_card_burner.py \
	utils/usrp2_card_burner_gui.py \
	utils/usrp_n2xx_net_burner.py \
	utils/usrp_n2xx_net_burner_gui.py \
	uhd-firmware/fx2/utils/build_eeprom.py \
	uhd-firmware/fx2/utils/edit-gpif-b100.py \
	uhd-firmware/fx2/utils/edit-gpif.py \
	uhd-firmware/fx2/utils/generate_regs.py \
	uhd-firmware/zpu/bin/bin_to_mif.py \
	uhd-firmware/zpu/bin/bin_to_ram_macro_init.py \
	uhd-firmware/zpu/bin/divisors.py \
	uhd-firmware/zpu/bin/elf_to_sbf \
	uhd-firmware/zpu/bin/serial_loader \
	uhd-firmware/zpu/bin/uart_ihex_flash_loader.py \
	uhd-firmware/zpu/bin/uart_ihex_ram_loader.py \
	uhd-fpga/usrp1/gen_makefile_extra.py \
	uhd-fpga/usrp1/sdr_lib/gen_cordic_consts.py \
	uhd-fpga/usrp1/tb/makesine.pl \
	uhd-fpga/usrp1/toplevel/mrfm/mrfm.py \
	uhd-fpga/usrp1/toplevel/mrfm/mrfm_fft.py \
	uhd-fpga/usrp2/sdr_lib/gen_cordic_consts.py \
	uhd-fpga/usrp2/top/extract_usage.py \
	uhd-fpga/usrp2/top/python/check_inout.py \
	uhd-fpga/usrp2/top/python/check_timing.py \
	uhd-fpga/usrp3/top/python/bit_to_zynq_bin.py \
	uhd-fpga/usrp3/top/python/check_inout.py \
	uhd-fpga/usrp3/top/python/check_timing.py \
        uhd-fpga/usrp3/lib/io_port2/create-lvbitx.py \


REPLACE_PERL=	uhd-fpga/usrp1/tb/makesine.pl

REPLACE_BASH=	\
	uhd-fpga/usrp2/top/impactor.sh \
	uhd-fpga/usrp3/top/impactor.sh \
        uhd-fpga/usrp3/top/python/batch-build \

INSTALLATION_DIRS+=	share/uhd
INSTALLATION_DIRS+=	share/uhd/firmware
INSTALLATION_DIRS+=	share/uhd/fpga
INSTALLATION_DIRS+=	share/uhd/images

# Copy (too) upper directory files (which should be handled at post-install)
# to receive REPLACE_PYTHON conversion ( otherwise above the range )
post-patch:
	(cd ${WRKDIR}; \
	for i in firmware fpga images ; do \
	  ${MKDIR} ${WRKSRC}/uhd-$$i ;\
	${CP} -r ${WRKDIR}/uhd/$$i/* ${WRKSRC}/uhd-$$i ;\
	done)

do-configure:
	(cd $(WRKSRC) ; \
	cmake \
	-DCMAKE_BUILD_WITH_INSTALL_RPATH=TRUE \
	-DCMAKE_INSTALL_PREFIX=${PREFIX} \
	-DCMAKE_INSTALL_RPATH=${PREFIX}/lib \
	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH=FALSE \
	.)

post-install:
	for i in firmware fpga images ; do \
	  ${CP} -r ${WRKSRC}/uhd-$$i/* ${DESTDIR}${PREFIX}/share/uhd/$$i/;\
	done	

.include "../../lang/python/application.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/orc/buildlink3.mk"
.include "../../wip/mk/git-package.mk"

.include "../../mk/bsd.pkg.mk"
