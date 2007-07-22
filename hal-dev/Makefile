# $NetBSD: Makefile,v 1.1.1.1 2007/07/22 10:46:04 krub1 Exp $
#

DISTNAME=	hal-07222007
CATEGORIES=	sysutils
MASTER_SITES=	http://www.coris.org.uk/mrk/pkgsrc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mkirby@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/hal
COMMENT=	Specification and an implementation of a hardware abstraction layer

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config intltool

USE_LANGUAGES+=		c c++

WRKSRC=			${WRKDIR}/hal

HAL_USER?=		haldaemon
HAL_GROUP?=		haldaemon

PKG_GROUPS=		${HAL_GROUP}
PKG_USERS=		${HAL_USER}:${HAL_GROUP}

CONFIGURE_ARGS+=	--with-os-type=${LOWER_VENDOR}
CONFIGURE_ARGS+=	--with-hal-user=${HAL_USER}
CONFIGURE_ARGS+=	--with-hal-group=${HAL_GROUP}
CONFIGURE_ARGS+=	--with-pid-file=/var/run/hald.pid
CONFIGURE_ARGS+=	--with-socket-dir=/var
CONFIGURE_ARGS+=	--localstatedir=/var
CONFIGURE_ARGS+=	--with-pci-ids=${PREFIX}/share/pciids
CONFIGURE_ARGS+=	--with-usb-ids=${PREFIX}/share/usbids

PKGCONFIG_OVERRIDE+=	hal.pc.in
PKGCONFIG_OVERRIDE+=	hal-storage.pc.in

RCD_SCRIPTS+=		hald

DBUS_DIR=		${PKG_SYSCONFDIR}/dbus-1/system.d
#POLICYKIT_DIR=		${PKG_SYSCONFDIR}/PolicyKit/privilege.d


BUILD_DEFS+=		HAL_USER HAL_GROUP UDEV_RULES_DIR

EGDIR=			${PREFIX}/share/examples/hal
CONF_FILES=		${EGDIR}/hal.conf ${DBUS_DIR}/hal.conf



CHECK_PORTABILITY_SKIP+= configure tools/hal-system-power-reboot
CHECK_PORTABILITY_SKIP+= tools/linux/hal-system-power-suspend-linux
CHECK_PORTABILITY_SKIP+= tools/hal-system-power-shutdown
CHECK_PORTABILITY_SKIP+= tools/hal-system-power-hibernate
CHECK_PORTABILITY_SKIP+= tools/hal-system-power-suspend

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
#.include "../../wip/policykit/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../wip/libvolumeid/buildlink3.mk"
#.include "volume_id.mk"
.include "../../mk/bsd.pkg.mk"
