# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:47 thomasklausner Exp $

DISTNAME=	pytmux-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	misc python
MASTER_SITES=	https://pypi.python.org/packages/source/p/pytmux/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.python.org/packages/source/p/pytmux/
COMMENT=	Simple wrapper for tmux
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-docopt>=0.6.1:../../wip/py-docopt
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=1.1.0:../../wip/py-jsonschema

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
