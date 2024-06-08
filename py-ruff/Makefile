# $NetBSD: Makefile,v 1.24 2024/05/10 11:14:21 adam Exp $

DISTNAME=	ruff-0.4.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruff/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astral-sh/ruff
COMMENT=	Extremely fast Python linter, written in Rust
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin>=1.0:../../devel/py-maturin

# for tikv-jemalloc-sys
USE_TOOLS+=	gmake

-lsp-types=	{ git = "https://github.com/astral-sh/lsp-types.git", rev = "3512a9f", features = ["proposed"] }
LSP_TYPES_REV=	3512a9f33eadc5402cfab1b8f7340824c8ca1439
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	lsp-types-${LSP_TYPES_REV}.tar.gz
SITES.lsp-types-${LSP_TYPES_REV}.tar.gz+= -${MASTER_SITE_GITHUB:=astral-sh/}lsp-types/archive/${LSP_TYPES_REV}.tar.gz

MAKE_ENV+=	CARGO_NET_OFFLINE=true

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-extract:
	mv ${WRKDIR}/lsp-types* ${WRKDIR}/lsp-types

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ruff ruff-${PYVERSSUFFIX} || ${TRUE}

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
