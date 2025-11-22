# $NetBSD$

DISTNAME=	safetensors-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/safetensors/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/safetensors/
COMMENT=	Simple, safe way to store and distribute tensors
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-rust>=1.11.1:../../devel/py-setuptools-rust

DEPENDS+=	${PYPKGPREFIX}-maturin-[0-9]*:../../devel/py-maturin

USE_LANGUAGES=	c

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
