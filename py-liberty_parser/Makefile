# $NetBSD$

DISTNAME=	liberty_parser-0.0.25
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S,^v,,}
CATEGORIES=	cad python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/liberty_parser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/liberty_parser/
COMMENT=	Library of functions to parse, manipulate and format 'Liberty' files
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-numpy>=1.0:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.6:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-lark>=1.1:../../wip/py-lark


.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
