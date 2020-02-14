# $NetBSD$

COMMENT=		Device enumeration and database of constants
CONFIGURE_ARGS+=	--disable-programs

pre-configure:
	sed -i 's/ERROR\(.*gperf\)/WARN\1/' ${WRKSRC}/configure.ac
	cd ${WRKSRC} &&autoreconf -fiv

.include "../../wip/libudev/Makefile.common"
