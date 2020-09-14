# $NetBSD$

DISTNAME=	desktop-notify-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	https://files.pythonhosted.org/packages/33/9a/2f786063cd0d5f16c82ee4b8dba11e2472e8fe4431bceb7300044e035aa0/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://gitlab.com/hxss/desktop-notify
COMMENT=	Util for sending desktop notifications over dbus
LICENSE=	mit

PYTHON_VERSIONS_ACCEPTED=	38 37

DEPENDS+=	${PYPKGPREFIX}-dbus-next>=0.1.3:../../wip/py-dbus-next

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
