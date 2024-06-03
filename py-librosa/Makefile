# $NetBSD$

DISTNAME=	librosa-0.10.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/librosa/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://librosa.org/
COMMENT=	Python module for audio and music processing
LICENSE=	isc

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-audioread-[0-9]*:../../audio/py-audioread
DEPENDS+=	${PYPKGPREFIX}-soundfile-[0-9]*:../../audio/py-soundfile
DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-msgpack-[0-9]*:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-pooch-[0-9]*:../../devel/py-pooch
DEPENDS+=	${PYPKGPREFIX}-joblib-[0-9]*:../../devel/py-joblib
DEPENDS+=	${PYPKGPREFIX}-numba-[0-9]*:../../math/py-numba
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scikit-learn-[0-9]*:../../math/py-scikit-learn
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-lazy_loader-[0-9]*:../../misc/py-lazy_loader
DEPENDS+=	${PYPKGPREFIX}-resampy-[0-9]*:../../wip/py-resampy
DEPENDS+=	${PYPKGPREFIX}-soxr-[0-9]*:../../wip/py-soxr
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
TEST_DEPENDS+=	${PYPKGPREFIX}-samplerate-[0-9]*:../../wip/py-samplerate
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mpl-[0-9]*:../../wip/py-test-mpl

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../audio/libsndfile/buildlink3.mk" # XXX: required for tests
.include "../../mk/bsd.pkg.mk"
