# $NetBSD$

DISTNAME=	gmqtt-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=wialon/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/wialon/gmqtt
COMMENT=	Python async MQTT client
LICENSE=	mit

WRKSRC=	${WRKDIR}/${DISTNAME}

TEST_DEPENDS+=	${PYPKGPREFIX}-atomicwrites>=1.3.0:../../devel/py-atomicwrites
TEST_DEPENDS+=	${PYPKGPREFIX}-attrs>=19.1.0:../../devel/py-attrs
TEST_DEPENDS+=	${PYPKGPREFIX}-codecov>=2.0.15:../../wip/py-codecov
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=4.5.3:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-more-itertools>=7.0.0:../../devel/py-more-itertools
TEST_DEPENDS+=	${PYPKGPREFIX}-pluggy>=0.11.0:../../devel/py-pluggy
TEST_DEPENDS+=	${PYPKGPREFIX}-py>=1.8.0:../../devel/py-py
TEST_DEPENDS+=	${PYPKGPREFIX}-six>=1.12.0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=5.4.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.12.0:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.7.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-uvloop>=0.14.0:../../devel/py-uvloop

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
