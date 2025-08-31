# $NetBSD$

COMMENT=	Portable FPGA place and route tool for Lattice iCE40 devices

NEXTPNR_TARGET=		ice40
NEXTPNR_TARGET_ARGS=	-DICESTORM_INSTALL_PREFIX=${PREFIX}

DEPENDS+=		icestorm>=0.0.20250603:../../devel/icestorm

.include "../../devel/nextpnr/nextpnr.mk"
