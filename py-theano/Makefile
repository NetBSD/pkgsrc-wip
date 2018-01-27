# $NetBSD$

DISTNAME=	Theano-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/28/03/6af9ff242da966f89de6ab81164db0d1a36fd89379b7370f07043de62f10/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://deeplearning.net/software/theano/
COMMENT=	Optimizing compiler for evaluating mathematical expressions
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.7:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.17.0:../../math/py-scipy

USE_TOOLS+=	bash
USE_LANGUAGES=	c c++

PY_PATCHPLIST=	yes

do-test:
	${RUN} cd {WRKSRC}/theano/tests ; ${SETENV} {TEST_ENV} ${PYTHONBIN} main.py

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
