# $NetBSD$

DISTNAME=	typer-0.16.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/typer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fastapi/typer
COMMENT=	Library for building CLI tools
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend>=0:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-click>=8.0.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4.3:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-shellingham>=1.3.0:../../misc/py-shellingham
DEPENDS+=	${PYPKGPREFIX}-rich>=10.11.0:../../comms/py-rich

USE_LANGUAGES=	# none

# as of 0.16.0
# 5 errors
# due to py-shellingham looking for /proc/R/stat

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
