# $NetBSD$

DISTNAME=	hmmlearn-0.2.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hmmlearn/}


MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/hmmlearn/hmmlearn
COMMENT=	Algorithms for inference of Hidden Markov Models
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-numpy>=1.21.5:../../math/py-numpy

USE_LANGUAGES=	c c++ # none

do-test:
	cd ${WRKSRC} && pwd && ${SETENV} ${TEST_ENV} python${PYVERSSUFFIX} -m pytest

.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
