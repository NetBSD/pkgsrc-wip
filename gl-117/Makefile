# $NetBSD: Makefile,v 1.1.1.1 2003/09/04 16:05:06 xtraeme Exp $
#

DISTNAME=	gl-117-1.0-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gl-117/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://home.t-online.de/home/Primetime./gl-117/
COMMENT=	SDL action flight simulator

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=                yes
GNU_CONFIGURE=		yes

.include "../../devel/SDL/buildlink2.mk"
.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../graphics/Mesa/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
