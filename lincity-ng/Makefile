# $NetBSD: Makefile,v 1.2 2007/11/05 19:07:01 cheusov Exp $
#

DISTNAME=	lincity-ng-1.1.1
CATEGORIES=	games
MASTER_SITES=	http://download.berlios.de/lincity-ng/ \
               http://download2.berlios.de/lincity-ng/

EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://prdownload.berlios.de/lincity-ng/
COMMENT=	City Simulation Game

BUILD_DEPENDS+=	jam-[0-9]*:../../devel/jam

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

#MAKE_PROGRAM=	jam

do-build:
	cd ${WRKSRC} && jam
do-install:
	cd ${WRKSRC} && jam install

.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/SDL_gfx/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
