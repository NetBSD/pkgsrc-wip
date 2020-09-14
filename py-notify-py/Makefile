# $NetBSD$

DISTNAME=	notify_py-0.2.3
PKGNAME=        ${PYPKGPREFIX}-notify-py-0.2.3
CATEGORIES=	sysutils python
MASTER_SITES=	https://files.pythonhosted.org/packages/dd/e7/d769d2cfd468bc6add04cdd1cc8a15163b3fc2196c5d4b8b6d02cd714751/

MAINTAINER=     kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/ms7m/notify-py
COMMENT=	Cross-platform desktop notification library for Python
LICENSE=	mit

USE_TOOLS+=	bash

DEPENDS+=       ${PYPKGPREFIX}-loguru>=0.5.1:../../wip/py-loguru

REPLACE_BASH+=	notifypy/os_notifiers/binaries/Notificator.app/Contents/Resources/Scripts/notificator

post-extract:
	${CP} ${FILESDIR}/netbsd.py ${WRKSRC}/notifypy/os_notifiers

.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
