# $NetBSD: Makefile,v 1.2 2004/08/19 14:59:37 dhowland Exp $
#

DISTNAME=		realvnc-4.0
CATEGORIES=		net x11
MASTER_SITES=		http://www.realvnc.com/dist/
DISTFILES=		vnc-4.0-unixsrc.tar.gz \
			vnc-4.0-documentation.tar.gz

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://www.realvnc.com/
COMMENT=		Display X and Win32 desktops on remote X/Win32/Java displays

PKG_SKIP_REASON=	unfinished / fails to install

CONFLICTS+=		vnc-*
CONFLICTS+=		vncviewer-*

WRKSRC=			${WRKDIR}/vnc-4.0-unixsrc
DOCSRC=			${WRKDIR}/vnc-4.0-documentation

USE_PERL5=		yes
REPLACE_PERL=		vncserver
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes

SUBST_CLASSES=		pl
SUBST_STAGE.pl=		pre-install
SUBST_FILES.pl=		vncserver
SUBST_MESSAGE.pl=	"Fixing paths..."
SUBST_SED.pl=		-e "s|/usr/local/vnc/classes|${X11PREFIX}/share/vnc/classes|g"

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vncserver ${PREFIX}/bin/vncserver
	${INSTALL_PROGRAM} ${WRKSRC}/vncpasswd/vncpasswd ${PREFIX}/bin/vncpasswd
	${INSTALL_PROGRAM} ${WRKSRC}/vncviewer/vncviewer ${PREFIX}/bin/vncviewer
	${INSTALL_PROGRAM} ${WRKSRC}/vncconfig/vncconfig ${PREFIX}/bin/vncconfig
	${INSTALL_PROGRAM} ${WRKSRC}/x0vncserver/x0vncserver ${PREFIX}/bin/x0vncserver
	${INSTALL_PROGRAM} ${WRKSRC}/xc/programs/Xserver/Xvnc ${PREFIX}/bin/Xvnc

.include "../../mk/bsd.pkg.mk"
