# $NetBSD$

DISTNAME=	astutils-0.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=a/astutils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/johnyf/astutils
COMMENT=	Utilities for abstract syntax trees and parsing with PLY
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	ply>=3.4<=3.10:../../devel/ply
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=4.6.11:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
