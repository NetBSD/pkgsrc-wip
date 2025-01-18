# $NetBSD$

DISTNAME=	mozinfo-1.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www python
MASTER_SITES=	https://files.pythonhosted.org/packages/23/35/96cccb2244a08247f5c1b5e810d6117d35a30e4a3e29679ed0c7dd2406c6/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://wiki.mozilla.org/Auto-tools/Projects/Mozbase
COMMENT=	Library to get system information for use in Mozilla testing
LICENSE=	mpl-1.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-distro>=1.4.0:../../devel/py-distro
DEPENDS+=	${PYPKGPREFIX}-mozfile>=0.12:../../wip/py-mozfile

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
