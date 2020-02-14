# $NetBSD$

PKGNAME=		udev-243
COMMENT=		Hotplug daemon
CONFIGURE_ARGS+=	--disable-hwdb

pre-configure:
	cp ${FILESDIR}/rules.am ${WRKSRC}/rules/Makefile.am
	sed -i 's/.(PROGRAMS_SUBDIRS)/udev/' ${WRKSRC}/src/Makefile.am
	cp ${FILESDIR}/libudev.am ${WRKSRC}/src/libudev/Makefile.am
	sed -i 's/.(LN.*;/true;/' ${WRKSRC}/src/udev/Makefile.am
	sed -i 's,/run,"UDEV_ROOT_RUN",' ${WRKSRC}/src/udev/*.c
	cd ${WRKSRC} &&autoreconf -fiv

.include "../../devel/gperf/buildlink3.mk"
.include "../../wip/libudev/buildlink3.mk"
.include "../../wip/libudev/Makefile.common"
