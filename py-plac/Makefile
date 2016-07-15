# $NetBSD$

DISTNAME=	plac-0.9.6
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/6c/9b/9e9d461a646d1c874043e105e46cc458c16e5f76f2119c8e670ff5a8db97/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/micheles/plac
COMMENT=	The smartest command line arguments parser in the world
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/plac-0.9.6

USE_LANGUAGES=	# none

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/plac_runner.py ${WRKSRC}/plac_runner.py${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
