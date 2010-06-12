# $NetBSD: Makefile,v 1.1.1.1 2010/06/12 23:25:01 jihbed Exp $
#

DISTNAME=	thwab-2.2.3
CATEGORIES=	misc
MASTER_SITES=	http://www.ojuba.org/downloads/thwab/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://thwab.ojuba.org/
COMMENT=	Electronic Encyclopedia System

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

PKG_DESTDIR_SUPPORT=	user-destdir

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
