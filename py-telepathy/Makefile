# $NetBSD: Makefile,v 1.5 2012/10/07 13:57:31 asau Exp $
#

DISTNAME=	telepathy-python-0.15.15
PKGNAME=	${PYPKGPREFIX}-telepathy-0.15.15
CATEGORIES=	chat
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-python/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://telepathy.freedesktop.org/releases/telepathy-python/
COMMENT=	Python bindings for the Telepathy framework
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	# none

PY_PATCHPLIST=	yes

.include "../../lang/python/extension.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
