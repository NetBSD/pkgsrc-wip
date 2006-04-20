# $NetBSD: Makefile,v 1.7 2006/04/20 13:36:43 cheusov Exp $
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

CONFLICTS+=		vnc-*
CONFLICTS+=		vncviewer-*
CONFLICTS+=		vncviewer4-*

WRKSRC=			${WRKDIR}/${DISTNAME}/unix

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=        --with-installed-zlib
NO_INSTALL_MANPAGES=    yes

USE_TOOLS+=		perl:run
REPLACE_PERL=		vncserver

SUBST_CLASSES+=		pl
SUBST_STAGE.pl=		pre-install
SUBST_FILES.pl=		vncserver
SUBST_MESSAGE.pl=	Fixing paths...
SUBST_SED.pl=		-e "s|/usr/local/vnc/classes|${PREFIX}/share/vnc/classes|g"

.include "../../mk/bsd.prefs.mk"

# The distfile listed above is bogus, there is no direct link to download the
# file, so a special command must be used.  I lifted this from FreeBSD Ports.
pre-fetch:
.if !exists(${DISTDIR}/${DISTNAME}.tar.gz)
	cd ${DISTDIR} && ${FETCH_CMD} -o ${DISTNAME}.tar.gz 'http://www.realvnc.com/cgi-bin/download.cgi?product=free4/src/unix&acceptLicense=1&filever=4.1.1&filetype=tar_gz&haveDetails=1'
.endif

# This is also lifted from FreeBSD Ports.
post-extract:
	@cd ${WRKSRC} && ${TAR} -cf - -C ${WRKDIR} xc | ${TAR} -xf - && \
	${RM} -rf ${WRKDIR}/xc

post-patch:
	@cd ${WRKSRC} && ${TOOLS_PLATFORM.patch} -Np0 <xc.patch

post-build:
	@cd ${WRKSRC}/xc && ${MAKE} World

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vncserver ${PREFIX}/bin/vncserver
	${INSTALL_PROGRAM} ${WRKSRC}/vncpasswd/vncpasswd ${PREFIX}/bin/vncpasswd
	${INSTALL_PROGRAM} ${WRKSRC}/vncviewer/vncviewer ${PREFIX}/bin/vncviewer
	${INSTALL_PROGRAM} ${WRKSRC}/vncconfig/vncconfig ${PREFIX}/bin/vncconfig
	${INSTALL_PROGRAM} ${WRKSRC}/x0vncserver/x0vncserver ${PREFIX}/bin/x0vncserver
	${INSTALL_PROGRAM} ${WRKSRC}/xc/programs/Xserver/Xvnc ${PREFIX}/bin/Xvnc
	${INSTALL_PROGRAM} ${WRKSRC}/xc/programs/Xserver/Xvnc ${PREFIX}/bin/Xvnc
	${INSTALL_PROGRAM_DIR} ${PREFIX}/lib/modules/extensions
	${INSTALL_PROGRAM} ${WRKSRC}/xc/programs/Xserver/vnc/module/vnc.so ${PREFIX}/lib/modules/extensions/vnc.so
	${INSTALL_MAN} ${WRKSRC}/vncviewer/vncviewer.man ${PREFIX}/${PKGMANDIR}/man1/vncviewer.1
	${INSTALL_MAN} ${WRKSRC}/x0vncserver/x0vncserver.man ${PREFIX}/${PKGMANDIR}/man1/x0vncserver.1
	${INSTALL_MAN} ${WRKSRC}/vncpasswd/vncpasswd.man ${PREFIX}/${PKGMANDIR}/man1/vncpasswd.1
	${INSTALL_MAN} ${WRKSRC}/vncconfig/vncconfig.man ${PREFIX}/${PKGMANDIR}/man1/vncconfig.1
	${INSTALL_MAN} ${WRKSRC}/vncserver.man ${PREFIX}/${PKGMANDIR}/man1/vncserver.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/vnc/classes
	${INSTALL_DATA} ${WRKSRC}/../common/javabin/* ${PREFIX}/share/vnc/classes

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
