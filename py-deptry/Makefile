# $NetBSD$

DISTNAME=	deptry-0.25.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/deptry/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://deptry.com/
COMMENT=	Check for unused, missing and transitive dependencies
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin>=0:../../devel/py-maturin
DEPENDS+=	${PYPKGPREFIX}-click>=8:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-packaging>=23.2:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-requirements-parser>=0.11.0:../../devel/py-requirements-parser
TEST_DEPENDS+=	${PYPKGPREFIX}-inline-snapshot>=0.32.5:../../devel/py-inline-snapshot
TEST_DEPENDS+=	${PYPKGPREFIX}-pdm>=2.26.6:../../devel/py-pdm
TEST_DEPENDS+=	${PYPKGPREFIX}-pdm>=0:../../devel/py-pdm
TEST_DEPENDS+=	${PYPKGPREFIX}-poetry>=2.3.2:../../devel/py-poetry
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=7.0.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.8.0:../../devel/py-test-xdist

CARGO_GITHUB_CRATES=	astral-sh ruff e4c7f357777a2fdd34dbe6a98b1b7d3e7488f675
SUBST_NOOP_OK.gitcrate=	yes

PY_RENAME_BINARIES=	deptry

# manually provide wheel that testing framework would get via uv
do-test:
	cd ${WRKSRC} && ${MKDIR} build/functional_tests/deptry && \
		${CP} ${WHEELFILE} build/functional_tests/deptry/
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

# as of 0.25.1
# 23 failed, 194 passed, 3 skipped, 16 errors

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 315
DEPENDS+=	${PYPKGPREFIX}-tomli>=2.0.1:../../textproc/py-tomli
.endif

USE_LANGUAGES=	c

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
