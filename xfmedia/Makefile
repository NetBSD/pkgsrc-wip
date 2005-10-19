# $NetBSD: Makefile,v 1.6 2005/10/19 04:32:02 minskim Exp $
#

DISTNAME=		xfmedia-0.9.1
CATEGORIES=		multimedia
MASTER_SITES=		http://spuriousinterrupt.org/projects/xfmedia/files/
EXTRACT_SUFX=           .tar.bz2

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://spuriousinterrupt.org/projects/xfmedia/
COMMENT=		Xfce media player based on xine

USE_DIRS+=		xdg-1.2
USE_PKGINSTALL=         yes
USE_PKGLOCALEDIR=       yes
USE_LIBTOOL=            yes
GNU_CONFIGURE=          yes
USE_X11=                yes
USE_TOOLS+=             gmake pkg-config

OWN_DIRS=	${PKG_SYSCONFDIR}/xdg/xfmedia

CONF_FILES=    ${PREFIX}/share/xfmedia/keybindings.rc \
	       ${PKG_SYSCONFDIR}/xdg/xfmedia/keybindings.rc

post-install:
	${INSTALL} ${WRKSRC}/src/keybindings.rc \
	    ${PREFIX}/share/xfmedia/keybindings.rc

.include "../../audio/taglib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/libexo/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
