# $NetBSD$

DISTNAME=	ruby-sdl2-0.3.5
CATEGORIES=	devel audio graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ohai/ruby-sdl2
COMMENT=	Ruby extension library to use SDL2 library
LICENSE=	gnu-lgpl-v3

GEM_CLEANBUILD=	Makefile *.o *.m4

.include "../../lang/ruby/gem.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
