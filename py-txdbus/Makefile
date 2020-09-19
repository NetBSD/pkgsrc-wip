# $NetBSD$

DISTNAME=	txdbus-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils net python
MASTER_SITES=	https://files.pythonhosted.org/packages/4a/68/dfd06f3f349999cbbb31eade239fe76fbff2d6a905eb7d20449666d1b2ce/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/cocagne/txdbus
COMMENT=	Python implementation of the DBus protocol for Twisted applications
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
