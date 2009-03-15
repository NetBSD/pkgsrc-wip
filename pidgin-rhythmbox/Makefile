# $NetBSD: Makefile,v 1.1.1.1 2009/03/15 13:55:18 jihbed Exp $
#

DISTNAME=	pidgin-rhythmbox-2.0
CATEGORIES=	chat
MASTER_SITES=	http://jon.oberheide.org/projects/pidgin-rhythmbox/downloads/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://jon.oberheide.org/projects/pidgin-rhythmbox/
COMMENT=	Plugin for pidgin to support Rhythmbox

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

BUILD_DEPENDS+=	rhythmbox>=0.11.6:../../audio/rhythmbox

INSTALLATION_DIRS=	share/pidgin-rhythmbox

post-install:
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/pidgin-rhythmbox
	${INSTALL_DATA} ${WRKSRC}/NEWS ${PREFIX}/share/pidgin-rhythmbox
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/pidgin-rhythmbox


.include "../../chat/pidgin/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
