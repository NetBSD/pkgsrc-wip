# $NetBSD: Makefile,v 1.5 2015/04/10 12:26:52 krytarowski Exp $
#

DISTNAME=		system-tools-backends-2.10.2
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GNOME:=/sources/system-tools-backends/2.10/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://system-tools-backends.freedesktop.org/
COMMENT=		DBus interface for system configuration
LICENSE=		gnu-gpl-v2

PKG_OPTIONS_VAR=	PKG_OPTIONS.system-tools-backends
PKG_SUPPORTED_OPTIONS+=	polkit
PKG_SUGGESTED_OPTIONS+=	polkit
PLIST_VARS+=		polkit

.include "../../mk/bsd.options.mk"
.if !empty(PKG_OPTIONS:Mpolkit)
.include "../../security/polkit/buildlink3.mk"
PLIST.polkit=		yes
.endif

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=	${EGDIR}/org.freedesktop.SystemToolsBackends.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.freedesktop.SystemToolsBackends.conf

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		YES

STB_GROUP?=		stb-admin
PKG_GROUPS=		${STB_GROUP}
PKG_GROUPS_VARS+=	STB_GROUP

CONFIGURE_ARGS+=	--with-stb-group=${STB_GROUP}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

INSTALL_MAKE_FLAGS+=	systemddir=${EGDIR}

DEPENDS+=	p5-Net-DBus>=0.33.6:../../net/p5-Net-DBus

REPLACE_PERL+=	SystemToolsBackends.pl.in
REPLACE_PERL+=	Utils/*.pm

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
