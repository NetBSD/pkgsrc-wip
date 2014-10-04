# $NetBSD: Makefile,v 1.1 2014/10/04 21:41:46 jihbed Exp $

DISTNAME=	conda-3.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel sysutils python
MASTER_SITES=	https://pypi.python.org/packages/source/c/conda/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/conda/conda
COMMENT=	Package management tool
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/bin/conda ${WRKSRC}/bin/conda${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
