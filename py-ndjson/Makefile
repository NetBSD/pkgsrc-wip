# $NetBSD$

DISTNAME=	ndjson-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/ndjson/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/rhgrant10/ndjson
COMMENT=	JsonDecoder for ndjson
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner>=5.2:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.1.2:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
