# $NetBSD: Makefile,v 1.3 2005/10/17 05:02:28 dhowland Exp $
#

DISTNAME=		vnc-4_1_1-unixsrc
PKGNAME=		realvnc-4.1.1
CATEGORIES=		net x11
MASTER_SITES=		http://www.realvnc.com/dist/
DISTFILES=		vnc-4_1_1-unixsrc.tar.gz \
			X430src-1.tgz \
			X430src-2.tgz \
			X430src-3.tgz
SITES_X430src-1.tgz=	ftp://ftp.xfree.org/pub/XFree86/4.3.0/source/
SITES_X430src-2.tgz=	ftp://ftp.xfree.org/pub/XFree86/4.3.0/source/
SITES_X430src-3.tgz=	ftp://ftp.xfree.org/pub/XFree86/4.3.0/source/

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://www.realvnc.com/
COMMENT=		Display X and Win32 desktops on remote X/Win32/Java displays

PKG_SKIP_REASON=	See TODO

CONFLICTS+=		vnc-*
CONFLICTS+=		vncviewer-*

WRKSRC=			${WRKDIR}/${DISTNAME}/unix

#USE_IMAKE=		yes
USE_PERL5=		yes
REPLACE_PERL=		vncserver
GNU_CONFIGURE=		yes
#USE_PKGINSTALL=		yes

SUBST_CLASSES=		pl
SUBST_STAGE.pl=		pre-install
SUBST_FILES.pl=		vncserver
SUBST_MESSAGE.pl=	"Fixing paths..."
SUBST_SED.pl=		-e "s|/usr/local/vnc/classes|${X11PREFIX}/share/vnc/classes|g"

.include "../../mk/bsd.prefs.mk"

# The distfile listed above is bogus, there is no direct link to download the
# file, so a special command must be used.  I lifted this from FreeBSD Ports.
pre-fetch:
.if !exists(${DISTDIR}/${DISTNAME}.tar.gz)
	cd ${DISTDIR} && ${FETCH_CMD} -o ${DISTNAME}.tar.gz 'http://www.realvnc.com/cgi-bin/download.cgi?product=free4/src/unix&acceptLicense=1&filever=4.1.1&filetype=tar_gz&haveDetails=1'
.endif

# This is also lifted from FreeBSD Ports.
post-extract:
	cd ${WRKSRC} && ${TAR} -cf - -C ${WRKDIR} xc | ${TAR} -xf - && \
	${RM} -rf ${WRKDIR}/xc

post-patch:
	cd ${WRKSRC} && ${TOOLS_PLATFORM.patch} -Np0 <xc.patch

post-build:
	cd ${WRKSRC}/xc && ${IMAKE_MAKE} World

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vncserver ${PREFIX}/bin/vncserver
	${INSTALL_PROGRAM} ${WRKSRC}/vncpasswd/vncpasswd ${PREFIX}/bin/vncpasswd
	${INSTALL_PROGRAM} ${WRKSRC}/vncviewer/vncviewer ${PREFIX}/bin/vncviewer
	${INSTALL_PROGRAM} ${WRKSRC}/vncconfig/vncconfig ${PREFIX}/bin/vncconfig
	${INSTALL_PROGRAM} ${WRKSRC}/x0vncserver/x0vncserver ${PREFIX}/bin/x0vncserver
	${INSTALL_PROGRAM} ${WRKSRC}/xc/programs/Xserver/Xvnc ${PREFIX}/bin/Xvnc

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
