# $NetBSD: Makefile,v 1.9 2014/06/01 12:49:37 thomasklausner Exp $

DISTNAME=	monajat-2.3.1
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://launchpad.net/monajat/trunk/beta/+download/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://launchpad.net/monajat
COMMENT=	Monajat is a small application that popups Islamic prayers
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-notify-[0-9]*:../../sysutils/py-notify
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo

WRKSRC=			${WRKDIR}/${DISTNAME}
USE_TOOLS+=		intltool msgfmt
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-notify, py-gtk2, py-gobject

INSTALLATION_DIRS+=	bin

REPLACE_PYTHON+=	${WRKSRC}/monajat-applet

.include "../../devel/pango/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
