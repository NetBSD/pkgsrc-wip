# $NetBSD: Makefile,v 1.1 2015/01/03 06:32:07 obache Exp $
#

DISTNAME=		system-tools-backends-2.8.3
CATEGORIES=		sysutils
MASTER_SITES=		http://system-tools-backends.freedesktop.org/downloads/2.8/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://system-tools-backends.freedesktop.org/
COMMENT=		DBus interface for system configuration
LICENSE=		gnu-gpl-v2

PKG_OPTIONS_VAR=	PKG_OPTIONS.system-tools-backends
PKG_SUPPORTED_OPTIONS+=	polkit
PKG_SUGGESTED_OPTIONS+=	polkit
PLIST_VARS+=		polkit

.include "../../mk/bsd.options.mk"
.if !empty(PKG_OPTIONS:Mpolkit)
.include "../../wip/polkit/buildlink3.mk"
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

DEPENDS+=	p5-XML-Twig>=3.32:../../textproc/p5-XML-Twig
DEPENDS+=	p5-Net-DBus>=0.33.6:../../net/p5-Net-DBus
DEPENDS+=	p5-libwww>=5.820:../../www/p5-libwww
DEPENDS+=	p5-URI>=1.37:../../www/p5-URI

REPLACE_PERL+=	SystemToolsBackends.pl.in
REPLACE_PERL+=	Utils/*.pm

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
