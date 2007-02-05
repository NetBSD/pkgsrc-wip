# $NetBSD: Makefile,v 1.1.1.1 2007/02/05 00:03:41 pseudo_anim Exp $
#

DISTNAME=	guichan-0.6.0-src
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=guichan/}

MAINTAINER=	Pseudo.Statistic@gmail.com
HOMEPAGE=	http://guichan.sourceforge.net/
COMMENT= A portable C++ GUI library designed for games using Allegro, SDL and/or OpenGL	

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=             gmake
USE_LIBTOOL=            yes
GNU_CONFIGURE=          yes
SHLIBTOOL_OVERRIDE+=	libtool

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c++
CONFIGURE_ARGS+=	--disable-allegro

pre-configure:
	ln -sf ../../../../../pkg/share/libtool/ltmain.sh work/guichan-0.6.0-src/ltmain.sh

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
