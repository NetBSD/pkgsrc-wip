# $NetBSD$

DISTNAME=	Theano-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=T/Theano/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://deeplearning.net/software/theano/
COMMENT= 	Optimizing compiler for evaluating mathematical expressions
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.7:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.17.0:../../math/py-scipy

USE_TOOLS+=	bash

REPLACE_BASH+=	theano/misc/check_blas_many.sh

post-extract:
	${MV} ${WRKSRC}/bin/theano-cache ${WRKSRC}/bin/theano-cache${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/theano-nose ${WRKSRC}/bin/theano-nose${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/theano-test ${WRKSRC}/bin/theano-test${PYVERSSUFFIX}

do-test:
	${RUN} cd {WRKSRC}/theano/tests ; ${SETENV} {TEST_ENV} ${PYTHONBIN} main.py

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
