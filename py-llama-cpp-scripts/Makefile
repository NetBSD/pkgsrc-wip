# $NetBSD$

.include "../../wip/llama.cpp/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-llama-cpp-scripts-${GITHUB_TAG:S/b/${LLAMA_VER}./}
CATEGORIES=	devel
LLAMA_VER=	0.0.0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ggerganov/llama.cpp/
COMMENT=	Scripts that ship with llama.cpp
LICENSE=	mit

USE_LANGUAGES=	# none

BUILD_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core

DEPENDS+=	${PYPKGPREFIX}-numpy>=1.26.4:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-sentencepiece>=0.1.98:../../textproc/py-sentencepiece
DEPENDS+=	${PYPKGPREFIX}-transformers>=0.1.98:../../wip/py-transformers
DEPENDS+=	${PYPKGPREFIX}-protobuf>=4.21.0:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-torch>=2.6.0:../../math/py-torch
DEPENDS+=	${PYPKGPREFIX}-gguf-[0-9]*:../../wip/py-gguf

SCRIPTS=	llama-convert-hf-to-gguf \
		llama-convert-llama-ggml-to-gguf \
		llama-convert-lora-to-gguf \
		llama-ggml-vk-generate-shaders

post-install:
.for script in ${SCRIPTS}
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} ${script} ${script}-${PYVERSSUFFIX}
.endfor

PRINT_PLIST_AWK+=	{gsub(/${LLAMA_VER}/, "$${LLAMA_VER}");}

PLIST_SUBST+=	LLAMA_VER=${LLAMA_VER:Q}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
