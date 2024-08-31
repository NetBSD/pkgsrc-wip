# $NetBSD: Makefile,v 1.1 2024/01/06 23:24:02 leot Exp $

DISTNAME=	regress-0.4.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/regress/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/crate-py/regress
COMMENT=	Python bindings to the Rust regress crate
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin>=1:../../devel/py-maturin

MAKE_ENV+=	CARGO_NET_OFFLINE=true

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
