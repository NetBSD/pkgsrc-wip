# $NetBSD: Makefile,v 1.7 2015/08/18 21:15:41 yhardy Exp $

DISTNAME=	stone_soup-0.23.2-nodeps
PKGNAME=	dungeon-crawl-stone-soup-0.23.2
CATEGORIES=	games
MASTER_SITES=	http://crawl.develz.org/release/0.23/
EXTRACT_SUFX=	.tar.xz
WRKSRC=		${WRKDIR}/${DISTNAME:S/-nodeps//}/source

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://crawl.develz.org/wordpress/
COMMENT=	Dungeon Crawl Stone Soup is a role-playing roguelike game
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		pkg-config
USE_TOOLS+=		gmake
USE_TOOLS+=		perl
USE_TOOLS+=		python
USE_LANGUAGES=		c c++11
BUILD_MAKE_FLAGS+=	prefix=${PREFIX}
BUILD_MAKE_FLAGS+=	SAVEDIR='~/.crawl'
BUILD_MAKE_FLAGS+=	V=y
BUILD_MAKE_FLAGS+=	DATADIR=${PREFIX}/share/${PKGNAME}
BUILD_MAKE_FLAGS+=	NO_AUTO_OPT=YesPlease
#BUILD_MAKE_FLAGS+=	NO_OPTIMIZE=YesPlease
INSTALL_MAKE_FLAGS+=	prefix=${PREFIX}
INSTALL_MAKE_FLAGS+=	SAVEDIR='~/.crawl'
INSTALL_MAKE_FLAGS+=	V=y
INSTALL_MAKE_FLAGS+=	DATADIR=${PREFIX}/share/${PKGNAME}

REPLACE_PERL+=	util/*.pl
REPLACE_PERL+=	util/mac-crawl-build-update-cdo
REPLACE_PERL+=	util/gen-mi-enum
REPLACE_PERL+=	util/gather*
REPLACE_PERL+=	util/db_lint
REPLACE_PERL+=	util/checkwhite
REPLACE_PERL+=	util/good-depfile

BUILD_DEPENDS+=		${PYPKGPREFIX}-yaml-[0-9.]*:../../textproc/py-yaml
REPLACE_PYTHON+=	util/species-gen.py
REPLACE_PYTHON+=	util/txc
REPLACE_PYTHON+=	webserver/server.py
REPLACE_PYTHON+=	webserver/ws_handler.py

LUA_VERSIONS_INCOMPATIBLE=	52 53

.include "../../lang/lua/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
