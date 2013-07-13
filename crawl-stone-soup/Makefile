# $NetBSD: Makefile,v 1.5 2013/07/13 17:27:01 genolopolis Exp $
#

DISTNAME=	stone_soup-0.12.2-nodeps
PKGNAME=	dungeon-crawl-stone-soup
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=crawl-ref/}
EXTRACT_SUFX=	.tar.xz
WRKSRC=		${WRKDIR}/${DISTNAME:S/-nodeps//}/source

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://crawl.develz.org/wordpress/
COMMENT=	Dungeon Crawl Stone Soup is a role-playing roguelike game
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_TOOLS+=	gmake
USE_TOOLS+=	perl
USE_LANGUAGES=	c c++
BUILD_MAKE_FLAGS+=	prefix=${PREFIX}
BUILD_MAKE_FLAGS+=	SAVEDIR='~/.crawl'
BUILD_MAKE_FLAGS+=	V=y
BUILD_MAKE_FLAGS+=	DATADIR=${PREFIX}/share/${PKGNAME}
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

#SUBST_FILES.fix-paths=	source/Makefile
#SUBST_SED.fix-paths=	-e 's,"/usr/local,"${PREFIX},g'

#PKGCONFIG_OVERRIDE+=	source/contrib/pcre/libpcre.pc.in
#PKGCONFIG_OVERRIDE+=	source/contrib/pcre/libpcreposix.pc.in
#PKGCONFIG_OVERRIDE+=	source/contrib/pcre/libpcrecpp.pc.in
#PKGCONFIG_OVERRIDE+=	source/contrib/libpng/libpng.pc.in
#PKGCONFIG_OVERRIDE+=	source/contrib/libpng/scripts/libpng.pc.in
#PKGCONFIG_OVERRIDE+=	source/contrib/sdl/sdl.pc.in
#PKGCONFIG_OVERRIDE+=	source/contrib/sdl-image/SDL_image.pc.in

.include "../../lang/lua/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
