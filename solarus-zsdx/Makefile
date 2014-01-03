# $NetBSD: Makefile,v 1.3 2014/01/03 19:08:21 thomasklausner Exp $

DISTNAME=	zsdx-1.7.1
PKGNAME=	solarus-${DISTNAME}
CATEGORIES=	games
MASTER_SITES=	https://github.com/christopho/zsdx/archive/
FETCH_USING=	curl

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.solarus-games.org/games/zelda-mystery-of-solarus-dx/
COMMENT=	Zelda Mystery of Solarus DX
LICENSE=	gnu-gpl-v3 AND cc-by-sa-v3.0

DEPENDS+=	solarus-[0-9]*:../../games/solarus

WRKSRC=		${WRKDIR}/zsdx-${DISTNAME}
USE_LANGUAGES=	c c++
USE_TOOLS+=	zip
USE_CMAKE=	yes

SUBST_CLASSES+=		zsdx
SUBST_FILES.zsdx=	zsdx
SUBST_MESSAGE.zsdx=	Fixing zsdx invocation.
SUBST_SED.zsdx=		-e 's/ zsdx//1'
SUBST_STAGE.zsdx=	post-build

.include "../../mk/bsd.pkg.mk"
