# $NetBSD$

DISTNAME=	mozprocess-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils www python
MASTER_SITES=	https://files.pythonhosted.org/packages/3a/72/ecf7be35e24065c5780412627f4269a8bdae71eb42823d1416ea6968db11/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://firefox-source-docs.mozilla.org/mozbase/mozprocess.html
COMMENT=	Mozilla-authored process handling
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-mozinfo>=0:../../wip/py-mozinfo

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
