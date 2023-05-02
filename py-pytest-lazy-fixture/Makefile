# $NetBSD$

DISTNAME=	pytest-lazy-fixture-0.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-lazy-fixture/}

MAINTAINER=	matthewd@fastmail.us # or use pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tvorog/pytest-lazy-fixture
COMMENT=	It helps to use fixtures in pytest.mark.parametrize
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.8:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
