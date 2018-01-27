# $NetBSD: Makefile,v 1.25 2016/02/25 08:27:03 jperkin Exp $
#
DISTNAME=	scite375
PKGNAME=	scite-3.7.5
#PKGREVISION=	0
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scintilla/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://scintilla.sourceforge.net/
COMMENT=	Source code editor
LICENSE=	mit

WRKSRC=			${WRKDIR}/scite
USE_LANGUAGES=		c c++
BUILD_DIRS+=		gtk
USE_TOOLS+=		gmake pkg-config
MAKE_FILE=		makefile
INSTALLATION_DIRS=	share/applications share/pixmaps

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rm:-Wl,--version-script=lua.vers
#BUILDLINK_FNAME_TRANSFORM.SunOS+=	rm:-Wl,--version-script=lua.vers
.endif

post-extract:
	${RM} -r ${WRKDIR}/scintilla
	${RM} ${WRKSRC}/gtk/deps.mak
	${TOUCH} ${WRKSRC}/gtk/deps.mak

.include "../../devel/pango/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.scintilla+= scintilla>=3.7.4
.include "../../devel/scintilla/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
