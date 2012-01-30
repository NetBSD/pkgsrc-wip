# $NetBSD: Makefile,v 1.3 2012/01/30 03:31:42 noud4 Exp $
#

DISTNAME=	telepathy-butterfly-0.5.4
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-butterfly/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://telepathy.freedesktop.org/releases/telepathy-butterfly/
COMMENT=	Telepathy-butterfly is the MSN connection manager for telepathy
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-ctypes>=1.0.2:../../devel/py-ctypes
DEPENDS+=	${PYPKGPREFIX}-papyon>=0.4.4:../../wip/py-papyon
DEPENDS+=	${PYPKGPREFIX}-telepathy>=0.15.15:../../wip/py-telepathy

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 27 26 25
PY_PATCHPLIST=	yes

REPLACE_PYTHON+=	waf telepathy-butterfly

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
