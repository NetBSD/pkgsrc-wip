# $NetBSD: Makefile,v 1.1.1.1 2003/04/10 20:12:01 cubidou Exp $

DISTNAME=	gltron-0.62-source
PKGNAME=	${DISTNAME:S/-source$//}
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gltron/}

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://gltron.sourceforge.net/
COMMENT=	game inspired by the movie Tron

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES

.include "../../audio/SDL_sound/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../audio/libmikmod/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
