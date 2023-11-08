# $NetBSD$

DISTNAME=	pytmux-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytmux/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/wraithan/pytmux
#HOMEPAGE+=	https://pypi.org/project/pytmux/
COMMENT=	Simple wrapper for tmux
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-docopt>=0.6.1:../../devel/py-docopt
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=1.1.0:../../textproc/py-jsonschema

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
