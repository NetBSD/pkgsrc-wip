# $NetBSD$

DISTNAME=	pytmux-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytmux/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/wraithan/pytmux
#HOMEPAGE+=	https://pypi.org/project/pytmux/
COMMENT=	Simple wrapper for tmux
LICENSE=	apache-2.0

# \todo CSE by putting this in wheel.mk.
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.1:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-docopt>=0.6.1:../../devel/py-docopt
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=1.1.0:../../textproc/py-jsonschema

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
