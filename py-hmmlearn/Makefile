# $NetBSD$

DISTNAME=	hmmlearn-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hmmlearn/}
PKGREVISION=	1

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/hmmlearn/hmmlearn
COMMENT=	Algorithms for inference of Hidden Markov Models
LICENSE=	modified-bsd

TOOL_DEPENDS+=       ${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
TOOL_DEPENDS+=       ${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.21.5:../../math/py-numpy

USE_LANGUAGES=	c c++ # none

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest -s

.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
