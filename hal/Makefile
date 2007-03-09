# $NetBSD: Makefile,v 1.1.1.1 2007/03/09 08:40:44 ondratu Exp $
#

DISTNAME=	hal-0.5.8
CATEGORIES=	sysutils
MASTER_SITES=	http://people.freedesktop.org/~david/dist/

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/hal
COMMENT=	Specification and an implementation of a hardware abstraction layer

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config intltool

USE_LANGUAGES+=		c c++

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

PKGCONFIG_OVERRIDE+=	hal.pc.in
PKGCONFIG_OVERRIDE+=	hal-storage.pc.in

RCD_SCRIPTS+=		hald

DBUS_DIR=		${PKG_SYSCONFDIR}/dbus-1/system.d
POLICYKIT_DIR=		${PKG_SYSCONFDIR}/PolicyKit/privilege.d
UDEV_RULES_DIR?=	/etc/udev/rules.d

BUILD_DEFS+=		HAL_USER HAL_GROUP UDEV_RULES_DIR

EGDIR=			${PREFIX}/share/examples/hal
CONF_FILES=		${EGDIR}/hal.conf ${DBUS_DIR}/hal.conf
CONF_FILES+=		${EGDIR}/hal-power-cpufreq.privilege ${POLICYKIT_DIR}/hal-power-cpufreq.privilege
CONF_FILES+=		${EGDIR}/hal-power-hibernate.privilege ${POLICYKIT_DIR}/hal-power-hibernate.privilege
CONF_FILES+=		${EGDIR}/hal-power-poweroff.privilege ${POLICYKIT_DIR}/hal-power-poweroff.privilege
CONF_FILES+=		${EGDIR}/hal-power-reboot.privilege ${POLICYKIT_DIR}/hal-power-reboot.privilege
CONF_FILES+=		${EGDIR}/hal-power-suspend.privilege ${POLICYKIT_DIR}/hal-power-suspend.privilege
CONF_FILES+=		${EGDIR}/hal-storage-fixed-mount-all-options.privilege ${POLICYKIT_DIR}/hal-storage-fixed-mount-all-options.privilege
CONF_FILES+=		${EGDIR}/hal-storage-fixed-mount.privilege ${POLICYKIT_DIR}/hal-storage-fixed-mount.privilege
CONF_FILES+=		${EGDIR}/hal-storage-removable-mount-all-options.privilege ${POLICYKIT_DIR}/hal-storage-removable-mount-all-options.privilege
CONF_FILES+=		${EGDIR}/hal-storage-removable-mount.privilege ${POLICYKIT_DIR}/hal-storage-removable-mount.privilege
CONF_FILES+=		${EGDIR}/90-hal.rules ${UDEV_RULES_DIR}/90-hal.rules

CHECK_PORTABILITY_SKIP+= configure tools/hal-system-power-reboot
CHECK_PORTABILITY_SKIP+= tools/linux/hal-system-power-suspend-linux
CHECK_PORTABILITY_SKIP+= tools/hal-system-power-shutdown
CHECK_PORTABILITY_SKIP+= tools/hal-system-power-hibernate
CHECK_PORTABILITY_SKIP+= tools/hal-system-power-suspend

PYTHON_PATCH_SCRIPTS+=	tools/device-manager/hal-device-manager.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../wip/policykit/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "volume_id.mk"
.include "../../mk/bsd.pkg.mk"

# i can't get OS_VERSION as number :( so it could be easer way
# in if clause
MAJOR_OS_VERSION=	${OS_VERSION:S/${OS_VERSION:C/^[0-9]*\.[0-9]*//}//}
MINOR_OS_VERSION=	${OS_VERSION:C/^[0-9]*\.[0-9]*\.//:C/[^0-9].*//}

# It is possible to run hal on solaris and freebsd systems, may be
# on NetBSD too ??
.if ${OPSYS} != "Linux" || ${MAJOR_OS_VERSION} < 2.6 || \
	(${MAJOR_OS_VERSION} == 2.6 && ${MINOR_OS_VERSION} < 15)
ONLY_FOR_PLATFORM=	Linux>=-2.6.15-*
.endif
