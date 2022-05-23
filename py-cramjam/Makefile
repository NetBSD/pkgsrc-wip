# $NetBSD$

VERSION=		2.5.0.post3
PKGVERSION_NOREV=	${VERSION}
GITHUB_TAG=		v${PKGVERSION_NOREV}
DISTNAME=		pyrus-cramjam-${VERSION}
PKGNAME=		${PYPKGPREFIX}-cramjam-${VERSION}
WHEEL_NAME=		cramjam-2.5.0
GITHUB_PROJECT=		pyrus-cramjam
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=milesgranger/}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/milesgranger/pyrus-cramjam
COMMENT=	Extremely thin Python bindings to de/compression algorithms in Rust
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-maturin-[0-9]*:../../wip/py-maturin
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.18:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis

.include "cargo-depends.mk"

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} maturin-${PYVERSSUFFIX} pep517 \
		build-wheel -i ${PREFIX}/bin/python3.10 --compatibility off \
		--cargo-extra-args="--offline"

# Test Requires install
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest -s tests

WHEELFILE=		${WRKSRC}/target/wheels/*.whl

.include "../../lang/rust/cargo.mk"
.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
