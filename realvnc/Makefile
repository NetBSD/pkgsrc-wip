# $NetBSD: Makefile,v 1.1.1.1 2004/08/18 21:49:56 dhowland Exp $
#

DISTNAME=		realvnc-4.0
CATEGORIES=		net x11
MASTER_SITES=		http://www.realvnc.com/dist/
DISTFILES=		vnc-4.0-unixsrc.tar.gz \
			vnc-4.0-documentation.tar.gz

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://www.realvnc.com/
COMMENT=		Display X and Win32 desktops on remote X/Win32/Java displays

CONFLICTS+=		vnc-* vncviewer-*

WRKSRC=			${WRKDIR}/vnc-4.0-unixsrc
DOCSRC=			${WRKDIR}/vnc-4.0-documentation

USE_PERL5=		yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes
USE_BUILDLINK3=		yes

.include "../../mk/bsd.prefs.mk"

do-install:
	${SED} -e 's|/usr/local/vnc/classes|${X11PREFIX}/share/vnc/classes|g' \
		-e 's|/usr/bin/perl|${PERL5}|g' \
		< ${WRKSRC}/vncserver \
		> ${WRKSRC}/vncserver.local
	${INSTALL_SCRIPT} ${WRKSRC}/vncserver.local ${PREFIX}/bin/vncserver
	${INSTALL_PROGRAM} ${WRKSRC}/vncpasswd/vncpasswd ${PREFIX}/bin/vncpasswd
	${INSTALL_PROGRAM} ${WRKSRC}/vncviewer/vncviewer ${PREFIX}/bin/vncviewer
	${INSTALL_PROGRAM} ${WRKSRC}/vncconfig/vncconfig ${PREFIX}/bin/vncconfig
	${INSTALL_PROGRAM} ${WRKSRC}/x0vncserver/x0vncserver ${PREFIX}/bin/x0vncserver
	${INSTALL_PROGRAM} ${WRKSRC}/xc/programs/Xserver/Xvnc ${PREFIX}/bin/Xvnc

.include "../../mk/bsd.pkg.mk"
