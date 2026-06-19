# $NetBSD$

.include "../../wip/llama.cpp/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-llama-cpp-scripts-${GITHUB_TAG:S/b/${LLAMA_VER}./}
CATEGORIES=	devel
LLAMA_VER=	0.0.0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ggerganov/llama.cpp/
COMMENT=	Scripts that ship with llama.cpp
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.26.4:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-sentencepiece>=0.1.98:../../textproc/py-sentencepiece
DEPENDS+=	${PYPKGPREFIX}-transformers>=0.1.98:../../wip/py-transformers
DEPENDS+=	${PYPKGPREFIX}-protobuf>=4.21.0:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-torch>=2.6.0:../../math/py-torch
DEPENDS+=	${PYPKGPREFIX}-gguf-[0-9]*:../../wip/py-gguf
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
# also needs wget and appium modules, currently unpackaged

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 314 # py-torch

PY_RENAME_BINARIES+=	llama-convert-hf-to-gguf
PY_RENAME_BINARIES+=	llama-convert-llama-ggml-to-gguf
PY_RENAME_BINARIES+=	llama-convert-lora-to-gguf
PY_RENAME_BINARIES+=	llama-ggml-vk-generate-shaders

REPLACE_PYTHON+=	*.py

WHEEL_NAME=	llama_cpp_scripts-${LLAMA_VER}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
