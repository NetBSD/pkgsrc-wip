# $NetBSD: Makefile,v 1.2 2005/10/14 16:38:12 dhowland Exp $
#

DISTNAME=		xfmedia-0.9.1
CATEGORIES=		multimedia
MASTER_SITES=		http://spuriousinterrupt.org/projects/xfmedia/files/
EXTRACT_SUFX=           .tar.bz2

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://spuriousinterrupt.org/projects/xfmedia/
COMMENT=		Xfce media player based on xine

USE_PKGINSTALL=         yes
USE_PKGLOCALEDIR=       yes
USE_LIBTOOL=            yes
GNU_CONFIGURE=          yes
USE_X11=                yes
USE_TOOLS+=             gmake pkg-config

CONF_FILES=    ${PREFIX}/share/xfmedia/keybindings.rc \
	       ${PKG_SYSCONFDIR}/xdg/xfmedia/keybindings.rc

post-install:
	${INSTALL} ${WRKSRC}/src/keybindings.rc \
	    ${PREFIX}/share/xfmedia/keybindings.rc

.include "../../x11/libexo/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
