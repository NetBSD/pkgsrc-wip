# $NetBSD: Makefile,v 1.13 2010/06/13 22:47:20 thomasklausner Exp $

DISTNAME=	Tuxtype2-${VERSION}
PKGNAME=	tuxtype2-${VERSION}
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tuxtype/}

MAINTAINER=	reed@reedmedia.net
COMMENT=	Educational typing tutorial game for children
HOMEPAGE=	http://tuxtype.sourceforge.net/

VERSION=	1.5.0

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
