# $NetBSD$

DISTNAME=	ruff-0.0.263
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruff/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/charliermarsh/ruff
COMMENT=	Extremely fast Python linter, written in Rust
LICENSE=	mit

#TOOL_DEPENDS+=	${PYPKGPREFIX}-build-[0-9]*:../../devel/py-build
#TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin>=0.14.10:../../devel/py-maturin
TOOL_DEPENDS+=	rust-[0-9]*:../../lang/rust

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
