# $NetBSD$

DISTNAME=	Mudlet-3.0.1
PKGREVISION=	1
CATEGORIES=	wip
MASTER_SITES=	https://www.mudlet.org/wp-content/files/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	chris@sogubsys.com
HOMEPAGE=	https://www.mudlet.org/
COMMENT=	Mudlet is a powerful GUI MUD client with Lua scripting
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR} # More than one possibility -- please check manually.
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

DEPENDS+=	lua[0-9]*-lrexlib-pcre-[0-9]*:../../devel/lua-lrexlib-pcre
DEPENDS+=	lua[0-9]*-filesystem-[0-9]*:../../devel/lua-filesystem
DEPENDS+=	lua[0-9]*-sql-sqlite3-[0-9]*:../../databases/lua-sql-sqlite3


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mudlet ${DESTDIR}${PREFIX}/bin



.include "../../devel/cmake/buildlink3.mk"
.include "../../lang/lua51/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
