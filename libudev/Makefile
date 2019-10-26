# $NetBSD$

COMMENT=	Device enumeration and database of constants
CONFIGURE_ARGS+=	--disable-programs

pre-configure:
	cd ${WRKSRC} &&autoreconf -fiv

.include "../../wip/libudev/Makefile.common"
