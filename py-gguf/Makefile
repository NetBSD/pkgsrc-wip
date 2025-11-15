# $NetBSD$

DISTNAME=	llama.cpp-${GITHUB_TAG}
PKGNAME=	${PYPKGPREFIX}-gguf-${GITHUB_TAG:S/b/${GGUF_VER}./}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ggml-org/}
GITHUB_TAG=	b6959
GGUF_VER=	0.17.1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/gguf/
COMMENT=	Read and write ML models in GGUF for GGML
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core

USE_LANGUAGES=	# none

WRKSRC=		${WRKDIR}/${DISTNAME}
PYSETUPSUBDIR=	gguf-py

PRINT_PLIST_AWK+=	{gsub(/${GGUF_VER}/, "$${GGUF_VER}");}

PLIST_SUBST+=	GGUF_VER=${GGUF_VER:Q}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
