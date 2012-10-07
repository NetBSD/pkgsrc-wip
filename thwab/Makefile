# $NetBSD: Makefile,v 1.2 2012/10/07 17:17:35 asau Exp $
#

DISTNAME=	thwab-2.2.3
CATEGORIES=	misc
MASTER_SITES=	http://www.ojuba.org/downloads/thwab/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://thwab.ojuba.org/
COMMENT=	Electronic Encyclopedia System

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=	intltool msgfmt
USE_LANGUAGES=		# none

PYDISTUTILSPKG=	yes
REPLACE_PYTHON+=	Thwab Othman

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/SimplifiedNaskh.ttf ${DESTDIR}${FONTDIR}

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
