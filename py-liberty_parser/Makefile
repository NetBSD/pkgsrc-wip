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

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
