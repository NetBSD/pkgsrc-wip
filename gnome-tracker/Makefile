# $NetBSD: Makefile,v 1.13 2013/06/19 12:15:39 noud4 Exp $

DISTNAME=	tracker-1.8.0
PKGNAME=	gnome-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/tracker/1.8/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Tracker
COMMENT=	Desktop-neutral metadata-based search framework
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

CONFLICTS+=	tracker-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config intltool gmake

PKG_SYSCONFSUBDIR=	xdg/autostart
MAKE_DIRS+=		${PKG_SYSCONFDIR}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=		${EGDIR}/xdg/autostart/tracker-extract.desktop \
			${PKG_SYSCONFDIR}/tracker-extract.desktop
CONF_FILES+=		${EGDIR}/xdg/autostart/tracker-miner-apps.desktop \
			${PKG_SYSCONFDIR}/tracker-miner-apps.desktop
CONF_FILES+=		${EGDIR}/xdg/autostart/tracker-miner-fs.desktop \
			${PKG_SYSCONFDIR}/tracker-miner-fs.desktop
CONF_FILES+=		${EGDIR}/xdg/autostart/tracker-miner-user-guides.desktop \
			${PKG_SYSCONFDIR}/tracker-miner-user-guides.desktop
CONF_FILES+=		${EGDIR}/xdg/autostart/tracker-store.desktop \
			${PKG_SYSCONFDIR}/tracker-store.desktop

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

REPLACE_PYTHON+=	tests/*/*.py
REPLACE_PYTHON+=	tests/*/*/*.py
REPLACE_PYTHON+=	examples/rss-reader/*.py
REPLACE_PYTHON+=	utils/*/*.py
REPLACE_PYTHON+=	utils/*/*/*.py

# Options?
CONFIGURE_ARGS+=	--disable-miner-thunderbird
CONFIGURE_ARGS+=	--disable-miner-firefox
CONFIGURE_ARGS+=	--disable-miner-evolution

.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
