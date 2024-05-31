# $NetBSD$

DISTNAME=	tinygrad-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_GITHUB:=tinygrad/}
GITHUB_PROJECT=	${DISTNAME:C/-[^-]*$//}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	mdehling@gmail.com
HOMEPAGE=	https://github.com/tinygrad/tinygrad
COMMENT=	Something between PyTorch and karpathy/micrograd
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-tqdm-[0-9]*:../../misc/py-tqdm
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
#TEST_DEPENDS+=	${PYPKGPREFIX}-librosa-[0-9]*:../../wip/py-librosa
#TEST_DEPENDS+=	${PYPKGPREFIX}-onnx-[0-9]*:../../wip/py-onnx
#TEST_DEPENDS+=	${PYPKGPREFIX}-tiktoken-[0-9]*:../../wip/py-tiktoken
#TEST_DEPENDS+=	${PYPKGPREFIX}-torch-[0-9]*:../../wip/py-torch

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	#cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest test/
	# XXX: ${TEST_ENV} defines ${PYTHON} which confuses Device.DEFAULT
	cd ${WRKSRC} && ${PYTHONBIN} -m pytest test/

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
