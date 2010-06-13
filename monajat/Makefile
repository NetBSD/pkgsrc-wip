# $NetBSD: Makefile,v 1.2 2010/06/13 22:47:11 thomasklausner Exp $
#

DISTNAME=	monajat-2.3.1
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://launchpad.net/monajat/trunk/beta/+download/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://launchpad.net/monajat
COMMENT=	Monajat is a small application that popups Islamic prayers
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_TOOLS+=	msgfmt intltool
USE_PKGLOCALEDIR=yes
USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

INSTALLATION_DIRS+=	bin

REPLACE_PYTHON+=   ${WRKSRC}/monajat-applet

.include "../../devel/pango/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/py-notify/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
