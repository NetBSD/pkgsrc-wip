# $NetBSD: Makefile,v 1.5 2003/08/22 16:39:15 xtraeme Exp $

DISTNAME=	Tuxtype2-${VERSION}
PKGNAME=	tuxtype2-${VERSION}
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tuxtype/}

MAINTAINER=	reed@reedmedia.net
COMMENT=	Educational typing tutorial game for children
HOMEPAGE=	http://tuxtype.sourceforge.net/

VERSION=	1.5.0

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
INFO_DIR=	share/tuxtype2/data/text
INFO_FILES=	english.info spanish.info menu.info

.include "../../graphics/SDL_image/buildlink2.mk"
.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../devel/SDL_ttf/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
