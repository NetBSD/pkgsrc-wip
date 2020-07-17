# $NetBSD$

PKGNAME=		udev-243
COMMENT=		Hotplug daemon
CONFIGURE_ARGS+=	--disable-hwdb

SUBST_CLASSES+=		nobin
SUBST_STAGE.nobin=	pre-configure
SUBST_FILES.nobin=	src/udev/Makefile.am
SUBST_SED.nobin=	's,.(LN.*;,true;,'

SUBST_CLASSES+=		onlyudev
SUBST_STAGE.onlyudev=	pre-configure
SUBST_FILES.onlyudev=	src/Makefile.am
SUBST_SED.onlyudev=	's,.(PROGRAMS_SUBDIRS),udev,'

SUBST_CLASSES+=		rootrun
SUBST_STAGE.rootrun=	pre-configure
SUBST_FILES.rootrun=	src/udev/*.c
SUBST_SED.rootrun=	's,/run,"UDEV_ROOT_RUN",'

pre-configure:
	${CP} ${FILESDIR}/rules.am ${WRKSRC}/rules/Makefile.am
	${CP} ${FILESDIR}/libudev.am ${WRKSRC}/src/libudev/Makefile.am
	cd ${WRKSRC} &&autoreconf -fiv

.include "../../devel/gperf/buildlink3.mk"
.include "../../wip/libudev/buildlink3.mk"
.include "../../wip/libudev/Makefile.common"
