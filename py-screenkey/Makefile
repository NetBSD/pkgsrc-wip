# $NetBSD$

DISTNAME=	screenkey-1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc x11
MASTER_SITES=	https://www.thregr.org/~wavexx/software/screenkey/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.thregr.org/~wavexx/software/screenkey/
COMMENT=	Screencast tool to display your keys
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	${PYPKGPREFIX}-babel-[0-9]*:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo
DEPENDS+=	${PYPKGPREFIX}-dbus-[0-9]*:../../sysutils/py-dbus

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
