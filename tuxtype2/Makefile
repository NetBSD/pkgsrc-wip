# $NetBSD: Makefile,v 1.11 2006/09/14 19:22:11 dhowland Exp $

DISTNAME=	Tuxtype2-${VERSION}
PKGNAME=	tuxtype2-${VERSION}
PKGREVISION=	1
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
