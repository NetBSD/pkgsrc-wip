# $NetBSD: Makefile,v 1.8 2014/05/09 07:38:52 thomasklausner Exp $

DISTNAME=	telepathy-butterfly-0.5.4
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-butterfly/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://telepathy.freedesktop.org/releases/telepathy-butterfly/
COMMENT=	Telepathy-butterfly is the MSN connection manager for telepathy
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-papyon>=0.4.4:../../wip/py-papyon
DEPENDS+=	${PYPKGPREFIX}-telepathy>=0.15.15:../../wip/py-telepathy

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

PY_PATCHPLIST=	yes

REPLACE_PYTHON+=		waf telepathy-butterfly
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-gobject, py-papyon

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
