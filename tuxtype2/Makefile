# $NetBSD: Makefile,v 1.2 2003/06/02 15:47:30 jeremy-c-reed Exp $

DISTNAME=	Tuxtype2-${VERSION}
PKGNAME=	tuxtype2-${VERSION}
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tuxtype/}

MAINTAINER=	reed@reedmedia.net
COMMENT=	educational typing tutorial game for children
HOMEPAGE=	http://tuxtype.sourceforge.net/

VERSION=	1.5.0

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

CFLAGS+=        -DDEBUG

.include "../../graphics/SDL_image/buildlink2.mk"
.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../devel/SDL_ttf/buildlink2.mk"

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
