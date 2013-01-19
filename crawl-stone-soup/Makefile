# $NetBSD: Makefile,v 1.1 2013/01/19 16:23:58 genolopolis Exp $
#

DISTNAME=	stone_soup-0.11.1
PKGNAME=	crawl-stone-soup
CATEGORIES=	games
MASTER_SITES=	http://downloads.sourceforge.net/project/crawl-ref/Stone%20Soup/0.11.1/
EXTRACT_SUFX=	.tar.xz
WRKSRC=		${WRKDIR}/${DISTNAME}/source

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://downloads.sourceforge.net/project/crawl-ref/Stone%20Soup/0.11.1/
COMMENT=	Dungeon Crawl Stone Soup is an open-source, single-player, role-playing roguelike game
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_TOOLS+=	gmake
USE_TOOLS+=	perl
USE_LANGUAGES=	c c++
BUILD_MAKE_FLAGS+=	prefix=${PREFIX}
BUILD_MAKE_FLAGS+=	savedir='~'
BUILD_MAKE_FLAGS+=	V=y
BUILD_MAKE_FLAGS+=	DATADIR=${PREFIX}/share/${PKGNAME}
INSTALL_MAKE_FLAGS+=	prefix=${PREFIX}
INSTALL_MAKE_FLAGS+=	savedir='~'
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

PKGCONFIG_OVERRIDE+=	source/contrib/pcre/libpcre.pc.in
PKGCONFIG_OVERRIDE+=	source/contrib/pcre/libpcreposix.pc.in
PKGCONFIG_OVERRIDE+=	source/contrib/pcre/libpcrecpp.pc.in
PKGCONFIG_OVERRIDE+=	source/contrib/libpng/libpng.pc.in
PKGCONFIG_OVERRIDE+=	source/contrib/libpng/scripts/libpng.pc.in
PKGCONFIG_OVERRIDE+=	source/contrib/sdl/sdl.pc.in
PKGCONFIG_OVERRIDE+=	source/contrib/sdl-image/SDL_image.pc.in

.include "../../lang/lua/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
