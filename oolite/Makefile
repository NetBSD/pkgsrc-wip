# $NetBSD: Makefile,v 1.4 2012/10/03 21:32:46 asau Exp $

DISTNAME=	oolite-1.65
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://download.berlios.de/oolite-linux/ \
		http://download2.berlios.de/oolite-linux/

DISTFILES=	${DISTNAME}-src${EXTRACT_SUFX}
DISTFILES+=	${DISTNAME}-data${EXTRACT_SUFX}

WRKSRC=		${WRKDIR}/${DISTNAME}-src

MAINTAINER=	pkgsrc-users@pkgsrc.org
COMMENT=	Space sim game, inspired by Elite
HOMEPAGE=	http://oolite.aegidian.org/


USE_LANGUAGES=	objc
USE_TOOLS+=	gmake
NO_CONFIGURE=	yes

MAKE_FILE=	GNUmakefile
MAKE_JOBS_SAFE=	no

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
