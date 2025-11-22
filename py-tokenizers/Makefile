# $NetBSD$

DISTNAME=	tokenizers-0.22.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python # TODO: add primary category
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tokenizers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/tokenizers/
COMMENT=	TODO: Short description of the package
LICENSE=	apache-2.0

# TODO: Extract dependencies from pyproject.toml

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-rust>=1.11.1:../../devel/py-setuptools-rust

USE_LANGUAGES=	c c++

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
