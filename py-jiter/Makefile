# $NetBSD$

DISTNAME=	jiter-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jiter/}

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://pypi.org/project/jiter/
COMMENT=	Standalone version of the JSON parser used in pydantic-core
LICENSE=	mit

.include "cargo-depends.mk"

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

PYTHON_VERSIONS_INCOMPATIBLE=	27 313

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
