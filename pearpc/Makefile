# $NetBSD: Makefile,v 1.2 2004/05/22 02:29:47 xtraeme Exp $
#

DISTNAME=		pearpc-0.1.2
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pearpc/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://pearpc.sourceforge.net/
COMMENT=		PowerPC emulator

ONLY_FOR_PLATFORMS=	NetBSD-*-* Linux-*-i386

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_X11=		yes

LIBS+=			${PTHREAD_LDFLAGS}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/ppccfg.example ${PKG_SYSCONFDIR}/ppcfg.conf

.ifdef NOT_YET
BUILD_DEFS+=		USE_QT_GUI

.if defined(USE_QT_GUI) && !empty(USE_QT_GUI:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-gui=qt
.include "../../x11/qt3-libs/buildlink3.mk"
.endif

.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ppc ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/ppccfg.example ${EGDIR}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
