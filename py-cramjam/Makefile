# $NetBSD$

DISTNAME=	cramjam-2.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cramjam/}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/milesgranger/pyrus-cramjam
COMMENT=	Extremely thin Python bindings to de/compression algorithms in Rust
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-maturin-[0-9]*:../../wip/py-maturin
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest -s tests

USE_LANGUAGES=	c

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
