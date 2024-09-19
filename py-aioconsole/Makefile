# $NetBSD$

DISTNAME=	aioconsole-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aioconsole/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/vxgmichel/aioconsole
COMMENT=	Asynchronous console and interfaces for asyncio
LICENSE=	gnu-gpl-v3


TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.1.1:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=6.1.1:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.10.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-repeat>=0.8.0:../../wip/py-test-repeat

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
