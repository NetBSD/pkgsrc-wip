# $NetBSD: Makefile,v 1.2 2007/12/02 21:01:02 ondratu Exp $
#

DISTNAME=	PolicyKit-0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://hal.freedesktop.org/releases/

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/hal
COMMENT=	Framework for defining policy for system-wide components

BUILD_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl

# i'm not sure which pams are acceptable
#PAM_ACCEPTED=		linux-pam

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

USE_LANGUAGES+=		c c++

POLKID_USER?=		polkit
POLKID_GROUP?=		polkit

PKG_GROUPS=		${POLKID_GROUP}
PKG_USERS=		${POLKID_USER}:${POLKID_GROUP}
BUILD_DEFS+=		POLKID_USER POLKID_GROUP VARBASE

CONFIGURE_ARGS+=	--with-os-type=${LOWER_VENDOR}
CONFIGURE_ARGS+=	--with-polkit-user=${POLKID_USER}
CONFIGURE_ARGS+=	--with-polkit-group=${POLKID_GROUP}
CONFIGURE_ARGS+=	--with-pam-module-dir=${PAM_INSTMODULEDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

PKGCONFIG_OVERRIDE+=	data/polkit.pc.in data/polkit-dbus.pc.in data/polkit-grant.pc.in

PAM_DIR=		${PKG_SYSCONFDIR}/pam.d
MAKE_DIRS+=		${PKG_SYSCONFDIR}/PolicyKit
OWN_DIRS+=		${VARBASE}/run/PolicyKit ${VARBASE}/lib/PolicyKit

EGDIR=			${PREFIX}/share/examples/policykit
CONF_FILES+=		${EGDIR}/PolicyKit.conf ${PKG_SYSCONFDIR}/PolicyKit/PolicyKit.conf
CONF_FILES+=		${EGDIR}/polkit ${PAM_DIR}/polkit

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../security/PAM/module.mk"
.include "../../mk/bsd.pkg.mk"
