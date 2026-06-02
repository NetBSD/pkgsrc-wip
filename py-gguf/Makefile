# $NetBSD$

.include "../../wip/llama.cpp/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-gguf-${GITHUB_TAG:S/b/${GGUF_VER}./}
CATEGORIES=	devel
GGUF_VER=	0.19.0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/gguf/
COMMENT=	Read and write ML models in GGUF for GGML
LICENSE=	mit

USE_LANGUAGES=	# none

BUILD_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core

WRKSRC=		${WRKDIR}/${DISTNAME}
PYSETUPSUBDIR=	gguf-py

PRINT_PLIST_AWK+=	{gsub(/${GGUF_VER}/, "$${GGUF_VER}");}

PLIST_SUBST+=	GGUF_VER=${GGUF_VER:Q}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
