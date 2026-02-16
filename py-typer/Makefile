# $NetBSD$

DISTNAME=	typer-0.23.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/typer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fastapi/typer
COMMENT=	Library for building CLI tools
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend>=0:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-annotated_doc>=0.0.2:../../wip/py-annotated_doc
DEPENDS+=	${PYPKGPREFIX}-click>=8.0.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-shellingham>=1.3.0:../../misc/py-shellingham
DEPENDS+=	${PYPKGPREFIX}-rich>=10.11.0:../../comms/py-rich

USE_LANGUAGES=	# none

# as of 0.23.1
# 35 errors
# due to py-shellingham looking for /proc/R/stat
# https://github.com/sarugaku/shellingham/issues/99

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
