# $NetBSD: Makefile,v 1.18 2012/11/12 14:32:14 thomasklausner Exp $
#

DISTNAME=		vnc-4_1_2-unixsrc
PKGNAME=		realvnc-4.1.2
CATEGORIES=		net x11
MASTER_SITES=		https://www.realvnc.com/dist/
DISTFILES=		vnc-4_1_2-unixsrc.tar.gz \
			X430src-1.tgz \
			X430src-2.tgz \
			X430src-3.tgz
SITES.X430src-1.tgz=	http://ftp.gwdg.de/pub/xfree86/XFree86/4.3.0/source/
SITES.X430src-2.tgz=	http://ftp.gwdg.de/pub/xfree86/XFree86/4.3.0/source/
SITES.X430src-3.tgz=	http://ftp.gwdg.de/pub/xfree86/XFree86/4.3.0/source/

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		https://www.realvnc.com/
COMMENT=		Display X and Win32 desktops on remote X/Win32/Java displays

CONFLICTS+=		vnc-[0-9]*
CONFLICTS+=		vncviewer-[0-9]*
CONFLICTS+=		vncviewer4-[0-9]*

CONFIGURE_DIRS=		unix

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-installed-zlib
NO_INSTALL_MANPAGES=	yes

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl:run tar
REPLACE_PERL=		unix/vncserver

SUBST_CLASSES+=		pl
SUBST_STAGE.pl=		pre-install
SUBST_FILES.pl=		vncserver
SUBST_MESSAGE.pl=	Fixing paths...
SUBST_SED.pl=		-e "s|/usr/local/vnc/classes|${PREFIX}/share/vnc/classes|g"

.include "../../mk/bsd.prefs.mk"

# The distfile listed above is bogus, there is no direct link to download the
# file, so a special command must be used.  I lifted this from FreeBSD Ports.
DISTURL=https://www.realvnc.com/cgi-bin/download.cgi?product=free4/src/unix&acceptLicense=1&filever=4.1.2&filetype=tar_gz&haveDetails=1
pre-fetch:
.if !exists(${DISTDIR}/${DISTNAME}.tar.gz)
	cd ${DISTDIR} && ${FETCH_CMD} -o ${DISTNAME}.tar.gz ${DISTURL:Q}
.endif

# This is also lifted from FreeBSD Ports.
post-extract:
	cd ${WRKSRC}/unix && ${TAR} -cf - -C ${WRKDIR} xc | ${TAR} -xf - && \
	${RM} -rf ${WRKDIR}/xc

post-patch:
	cd ${WRKSRC}/unix && ${TOOLS_PLATFORM.patch} -Np0 <xc.patch

post-build:
	cd ${WRKSRC}/unix/xc && ${MAKE} World

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/unix/vncserver ${DESTDIR}${PREFIX}/bin/vncserver
	${INSTALL_PROGRAM} ${WRKSRC}/unix/vncpasswd/vncpasswd ${DESTDIR}${PREFIX}/bin/vncpasswd
	${INSTALL_PROGRAM} ${WRKSRC}/unix/vncviewer/vncviewer ${DESTDIR}${PREFIX}/bin/vncviewer
	${INSTALL_PROGRAM} ${WRKSRC}/unix/vncconfig/vncconfig ${DESTDIR}${PREFIX}/bin/vncconfig
	${INSTALL_PROGRAM} ${WRKSRC}/unix/x0vncserver/x0vncserver ${DESTDIR}${PREFIX}/bin/x0vncserver
	${INSTALL_PROGRAM} ${WRKSRC}/unix/xc/programs/Xserver/Xvnc ${DESTDIR}${PREFIX}/bin/Xvnc
	${INSTALL_PROGRAM} ${WRKSRC}/unix/xc/programs/Xserver/Xvnc ${DESTDIR}${PREFIX}/bin/Xvnc
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/lib/modules/extensions
	${INSTALL_PROGRAM} ${WRKSRC}/unix/xc/programs/Xserver/vnc/module/vnc.so ${DESTDIR}${PREFIX}/lib/modules/extensions/vnc.so
	${INSTALL_MAN} ${WRKSRC}/unix/vncviewer/vncviewer.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vncviewer.1
	${INSTALL_MAN} ${WRKSRC}/unix/x0vncserver/x0vncserver.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/x0vncserver.1
	${INSTALL_MAN} ${WRKSRC}/unix/vncpasswd/vncpasswd.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vncpasswd.1
	${INSTALL_MAN} ${WRKSRC}/unix/vncconfig/vncconfig.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vncconfig.1
	${INSTALL_MAN} ${WRKSRC}/unix/vncserver.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vncserver.1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/vnc/classes
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/common/javabin/* ${DESTDIR}${PREFIX}/share/vnc/classes

.include "../../devel/zlib/buildlink3.mk"
.if ${X11_TYPE} == "native"
.include "../../mk/x11.buildlink3.mk"
.else
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
