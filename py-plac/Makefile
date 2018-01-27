# $NetBSD$

DISTNAME=	plac-0.9.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/plac/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/micheles/plac
COMMENT=	The smartest command line arguments parser in the world
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

post-extract:
	${MV} ${WRKSRC}/plac_runner.py ${WRKSRC}/plac_runner.py${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
