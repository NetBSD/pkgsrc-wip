# $NetBSD: Makefile,v 1.13 2022/01/04 20:52:34 wiz Exp $

DISTNAME=	librosa-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/librosa/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://librosa.org/
COMMENT=	Python module for audio and music processing
LICENSE=	isc

DEPENDS+=	${PYPKGPREFIX}-audioread-[0-9]*:../../audio/py-audioread
DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-joblib-[0-9]*:../../devel/py-joblib
DEPENDS+=	${PYPKGPREFIX}-numba-[0-9]*:../../math/py-numba
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pooch-[0-9]*:../../devel/py-pooch
DEPENDS+=	${PYPKGPREFIX}-resampy-[0-9]*:../../wip/py-resampy
DEPENDS+=	${PYPKGPREFIX}-soundfile-[0-9]*:../../audio/py-soundfile
DEPENDS+=	${PYPKGPREFIX}-scikit-learn-[0-9]*:../../math/py-scikit-learn
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mpl-[0-9]*:../../wip/py-test-mpl
# test dependencies
#       contextlib2
#       samplerate
#       soxr

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
