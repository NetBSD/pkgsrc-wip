# $NetBSD: Makefile,v 1.1 2015/08/19 19:53:42 yhardy Exp $
#

VER=		0.7.0
DISTNAME=	nazghul-${VER}
PKGNAME=	haxima-${VER}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=project/nazghul/nazghul/nazghul-${VER}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://myweb.cableone.net/gmcnutt/nazghul.html
COMMENT=	Role playing game similar to Ultima 5
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
