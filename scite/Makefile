# $NetBSD: Makefile,v 1.25 2016/02/25 08:27:03 jperkin Exp $
#

DISTNAME=	scite446
PKGNAME=	scite-4.4.6
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scintilla/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://scintilla.sourceforge.net/
COMMENT=	Source code editor
LICENSE=	mit

WRKSRC=			${WRKDIR}/scite
GCC_REQD+=		7.1 # C++17 string_view
USE_LANGUAGES=		c c++
BUILD_DIRS+=		gtk
USE_TOOLS+=		gmake pkg-config
MAKE_FILE=		makefile
INSTALLATION_DIRS=	share/applications share/pixmaps

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=lua.vers

post-extract:
	${RM} -r ${WRKDIR}/scintilla
	${RM} ${WRKSRC}/gtk/deps.mak
	${TOUCH} ${WRKSRC}/gtk/deps.mak

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.scintilla+= scintilla>=4.4.6
.include "../../devel/scintilla/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
