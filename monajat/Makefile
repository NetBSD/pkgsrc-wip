# $NetBSD: Makefile,v 1.5 2013/12/06 11:31:35 noud4 Exp $
#

DISTNAME=	monajat-2.3.1
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://launchpad.net/monajat/trunk/beta/+download/
FETCH_USING=	curl

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://launchpad.net/monajat
COMMENT=	Monajat is a small application that popups Islamic prayers
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_TOOLS+=	intltool msgfmt
USE_PKGLOCALEDIR=	yes
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
DEPENDS+=	${PYPKGPREFIX}-notify-[0-9]*:../../sysutils/py-notify
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
