# $NetBSD: Makefile,v 1.5 2015/04/09 22:07:26 krytarowski Exp $
#

DISTNAME=	upower-0.9.16
CATEGORIES=	sysutils
MASTER_SITES=	https://upower.freedesktop.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://upower.freedesktop.org/releases/
COMMENT=	UPower is an abstraction for enumerating power devices
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

PKGCONFIG_OVERRIDE+=	upower-glib.pc.in

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=		${PREFIX}/share/examples/${PKGBASE}/UPower/UPower.conf \
			${PKG_SYSCONFDIR}/UPower/UPower.conf
CONF_FILES+=		${PREFIX}/share/examples/${PKGBASE}/dbus-1/system.d/org.freedesktop.UPower.conf \
			${PKG_SYSCONFDIR}/dbus-1/system.d/org.freedesktop.UPower.conf

OWN_DIRS+=	${VARBASE}/lib/upower
OWN_DIRS+=	${PKG_SYSCONFDIR}/UPower
MAKE_DIRS+=	${PKG_SYSCONFDIR}/dbus-1/system.d

BUILD_DEFS+=	VARBASE

.include "options.mk"

.include "../../security/polkit/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus+=	dbus>=1.0
.include "../../sysutils/dbus/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.76
.include "../../sysutils/dbus-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.21.5
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
