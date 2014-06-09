# $NetBSD: Makefile,v 1.1 2014/06/09 21:12:57 jihbed Exp $

DISTNAME=	dill-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/d/dill/
EXTRACT_SUFX=	.zip#md5=b2354a5717da6228acae33cb13bc407b

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.cacr.caltech.edu/~mmckerns/dill.htm
COMMENT=	Utility for serialization of python objects
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE= 30 31 32 33 34
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/scripts/get_objgraph.py ${WRKSRC}/scripts/get_objgraph.py${PYVERSSUFFIX}
	${MV} ${WRKSRC}/scripts/unpickle.py ${WRKSRC}/scripts/unpickle.py${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
