# $NetBSD$

DISTNAME=	ruff-0.0.264
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruff/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/charliermarsh/ruff
COMMENT=	Extremely fast Python linter, written in Rust
LICENSE=	mit

#TOOL_DEPENDS+=	${PYPKGPREFIX}-build-[0-9]*:../../devel/py-build
TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin>=0.14.10:../../devel/py-maturin
TOOL_DEPENDS+=	rust-[0-9]*:../../lang/rust

DISTFILES=					${DEFAULT_DISTFILES}
# Depends on unpublished crates. Can't use cargo.mk to fetch them.
LIBCST_REV=					80e4c1399f95e5beb532fdd1e209ad2dbb470438
DISTFILES+=					libcst-${LIBCST_REV}.tar.gz
SITES.libcst-${LIBCST_REV}.tar.gz+=		-${MASTER_SITE_GITHUB:=charliermarsh/}LibCST/archive/${LIBCST_REV}.tar.gz
# for ruff_text_size (and others)
RUSTPYTHON_REV=					c3147d2c1524ebd0e90cf1c2938d770314fd5a5a
DISTFILES+=					RustPython-${RUSTPYTHON_REV}.tar.gz
SITES.RustPython-${RUSTPYTHON_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=charliermarsh/}RustPython/archive/${RUSTPYTHON_REV}.tar.gz

post-extract:
	mv ${WRKDIR}/LibCST-* ${WRKSRC}
	mv ${WRKDIR}/RustPython-*/ruff_text_size ${WRKSRC}

CARGO_WRKSRC=	${WRKSRC}/crates/ruff_cli
MAKE_ENV+=	CARGO_NET_OFFLINE=true

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
