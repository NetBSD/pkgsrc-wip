# $NetBSD$

DISTNAME=	pyrefly-0.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyrefly/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/facebook/pyrefly
COMMENT=	Fast type checker and IDE for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin-[0-9]*:../../devel/py-maturin

USE_LANGUAGES=	c

# needed for 'make print-cargo-depends'
#WRKSRC=		${WRKDIR}/${DISTNAME}/pyrefly

.include "cargo-depends.mk"

# TODO: fix ruff dependencies
ALLOW_NETWORK_ACCESS=yes
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
