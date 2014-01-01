# $NetBSD: Makefile,v 1.1 2014/01/01 01:08:40 othyro Exp $

DISTNAME=	zsdx-1.7.1
PKGNAME=	solarus-${DISTNAME}
CATEGORIES=	games
MASTER_SITES=	https://github.com/christopho/zsdx/archive/
FETCH_USING=	curl

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.solarus-games.org/games/zelda-mystery-of-solarus-dx/
COMMENT=	Zelda Mystery of Solarus DX
LICENSE=	gnu-gpl-v3 AND cc-by-sa-v3.0

WRKSRC=		${WRKDIR}/zsdx-${DISTNAME}
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

DEPENDS+=	solarus-[0-9]*:../../games/solarus
.include "../../mk/bsd.pkg.mk"
