# $NetBSD: Makefile,v 1.3 2014/05/09 07:38:48 thomasklausner Exp $

DISTNAME=	py-notify-0.3.1
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}/1}-dev
CATEGORIES=	sysutils
MASTER_SITES=	http://download.gna.org/py-notify/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://pypi.python.org/pypi/py-notify/
COMMENT=	Python bindings for libnotify - development branch
LICENSE=	gnu-lgpl-v2.1

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-gtk2

CONFLICTS+=	${PYPKGPREFIX}-notify-[0-9]*

.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
