# $NetBSD$

DISTNAME=	nvchecker-2.20
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python devel net
MASTER_SITES=	${MASTER_SITE_GITHUB:=lilydjwg/}
GITHUB_PROJECT=	nvchecker
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lilydjwg/nvchecker/
COMMENT=	New version checker for software releases
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-curl>=0:../../www/py-curl
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=0:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-structlog>=0:../../sysutils/py-structlog
DEPENDS+=	${PYPKGPREFIX}-tornado>=0:../../www/py-tornado
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-lxml>=0:../../textproc/py-lxml

USE_LANGUAGES=	# none

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif
# as of 2.20
# 8 failed, 95 passed, 45 skipped, 23 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
