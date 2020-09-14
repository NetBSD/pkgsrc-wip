# $NetBSD$

DISTNAME=	Grammalecte-fr-v1.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S,-v,-,:tl}
CATEGORIES=	textproc
MASTER_SITES=	https://grammalecte.net/grammalecte/zip/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://grammalecte.net
COMMENT=	French grammar and typographic corrector
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}

USE_LANGUAGES=	# none

post-extract:
	${MV} ${WRKSRC}/grammalecte-cli.py ${WRKSRC}/grammalecte-cli.py${PYVERSSUFFIX}
	${MV} ${WRKSRC}/grammalecte-server.py ${WRKSRC}/grammalecte-server.py${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
