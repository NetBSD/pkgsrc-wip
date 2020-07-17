# $NetBSD$

COMMENT=		Device enumeration and database of constants
CONFIGURE_ARGS+=	--disable-programs

SUBST_CLASSES+=		nogperf
SUBST_STAGE.nogperf=	pre-configure
SUBST_FILES.nogperf=	configure.ac
SUBST_SED.nogperf=	's,ERROR\(.*gperf\),WARN\1,'

pre-configure:
	cd ${WRKSRC} &&autoreconf -fiv

.include "../../wip/libudev/Makefile.common"
