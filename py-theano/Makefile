# $NetBSD$

DISTNAME=	Theano-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=T/Theano/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://deeplearning.net/software/theano/
COMMENT= 	Optimizing compiler for evaluating mathematical expressions
LICENSE=	modified-bsd

WRKSRC=	${WRKDIR}/Theano-0.7.0

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/bin/theano-cache ${WRKSRC}/bin/theano-cache${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/theano-nose ${WRKSRC}/bin/theano-nose${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/theano-test ${WRKSRC}/bin/theano-test${PYVERSSUFFIX}

do-test:
	${RUN} cd {WRKSRC}/theano/tests ; ${SETENV} {TEST_ENV} ${PYTHONBIN} main.py

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy
.include "../../mk/bsd.pkg.mk"
