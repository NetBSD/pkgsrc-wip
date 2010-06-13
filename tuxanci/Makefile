# $NetBSD: Makefile,v 1.3 2010/06/13 22:47:20 thomasklausner Exp $
#

DISTNAME=	tuxanci-0.20.0-src
PKGNAME=	tuxanci-0.20.0
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://download.tuxanci.org/0.20.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://www.tuxanci.org/
COMMENT=	czechoslovak multiplatform action game like Bulanci

WRKSRC=	${WRKDIR}/pkgs/tuxanci-0.20.0-src

USE_CMAKE=      yes
USE_LANGUAGES+=	c c++

CMAKE_ARGS+= -DPREFIX=\\\"${PREFIX}/\\\" \
	     -DCMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
	     -DSDL_INCLUDE_DIR=${PREFIX}/include/SDL \
	     -DSDLIMAGE_INCLUDE_DIR=${PREFIX}/include/SDL \
	     -DSDLMIXER_INCLUDE_DIR=${PREFIX}/include/SDL \
	     -DSDLTTF_INCLUDE_DIR=${PREFIX}/include/SDL

.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
