# $NetBSD$

.include "../../wip/llama.cpp/Makefile.common"

GGUF_VER=	0.19.0
PKGNAME=	${PYPKGPREFIX}-gguf-${GITHUB_TAG:S/b/${GGUF_VER}./}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/gguf/
COMMENT=	Read and write ML models in GGUF for GGML
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.17:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1:../../textproc/py-yaml

REPLACE_PYTHON+=		gguf-py/gguf/*.py
REPLACE_PYTHON+=		gguf-py/gguf/scripts/*.py

USE_LANGUAGES=	# none

PYSETUPSUBDIR=	gguf-py

WHEEL_NAME=	gguf-${GGUF_VER}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
