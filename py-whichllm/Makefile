# $NetBSD$

DISTNAME=	whichllm-0.5.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Andyyyy64/}
GITHUB_PROJECT=	whichllm
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Andyyyy64/whichllm/
COMMENT=	Find the local LLM best for your hardware
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-httpx>=0.27:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-dbgpu>=1.0:../../wip/py-dbgpu
DEPENDS+=	${PYPKGPREFIX}-psutil>=5.9:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-rich>=13.0:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-typer>=0.9:../../devel/py-typer
#    "nvidia-ml-py>=12.0",

WRKSRC=		${WRKDIR}/${DISTNAME}

# TODO: Extract dependencies from pyproject.toml

USE_LANGUAGES=	# none

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
