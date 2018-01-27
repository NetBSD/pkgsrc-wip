# $NetBSD: Makefile,v 1.6 2012/09/29 00:50:41 asau Exp $
#

DISTNAME=		guichan-0.6.0-src
PKGNAME=		${DISTNAME:S/-src//}
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=guichan/}

MAINTAINER=	Pseudo.Statistic@gmail.com
HOMEPAGE=	http://guichan.sourceforge.net/
COMMENT=	Portable C++ GUI library for games


USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
SHLIBTOOL_OVERRIDE+=	libtool

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--disable-allegro

pre-configure:
	ln -sf ${PREFIX}/share/libtool/ltmain.sh ${WRKSRC}/ltmain.sh

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
