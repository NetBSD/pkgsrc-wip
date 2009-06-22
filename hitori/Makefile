# $NetBSD: Makefile,v 1.2 2009/06/22 14:06:47 jihbed Exp $
#

DISTNAME=	hitori-0.2.1
CATEGORIES=	games
MASTER_SITES=	http://tecnocode.co.uk/downloads/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://tecnocode.co.uk/projects/hitori/
COMMENT=	Hitori is an application that allow to play the eponymous puzzle game

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS+=	xdg-1.4
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake
USE_LANGUAGES+=	c c++

SHAREDIR=		${PREFIX}/share/hitori
INSTALLATION_DIRS=	share/hitori

post-install:
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${SHAREDIR}

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
