# $NetBSD: Makefile,v 1.48 2020/08/17 20:20:03 leot Exp $
#

DISTNAME=	conky-1.11.6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=brndnmtthws/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/brndnmtthws/conky/wiki
COMMENT=	Free, light-weight system monitor for X
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DRELEASE=ON

# XXX: investigate fixing this with NetBSD curses
CMAKE_ARGS+=	-DBUILD_NCURSES=OFF

EGDIR=		share/examples/conky
OWN_DIRS=	${PKG_SYSCONFDIR}/conky
CONF_FILES=	${EGDIR}/conky.conf ${PKG_SYSCONFDIR}/conky/conky.conf
CONF_FILES+=	${EGDIR}/conky_no_x11.conf ${PKG_SYSCONFDIR}/conky/conky_no_x11.conf

LUA_VERSIONS_ACCEPTED=	53 52

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/doc/conky-*/*.conf ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
