# $NetBSD: Makefile,v 1.3 2004/05/25 06:58:48 xtraeme Exp $
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
CONF_FILES=		${EGDIR}/ppccfg.example ${PKG_SYSCONFDIR}/ppccfg.conf

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_ARCH:Mi386)
BUILD_DEPENDS+=		nasm-[0-9]*:../../devel/nasm
CONFIGURE_ARGS+=	--enable-cpu=jitc_x86
.endif

.ifdef NOT_YET
BUILD_DEFS+=		USE_QT_GUI

.if defined(USE_QT_GUI) && !empty(USE_QT_GUI:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-gui=qt
.include "../../x11/qt3-libs/buildlink3.mk"
.endif

.endif

do-install:
	${SED} -e "s,@PREFIX@,${PREFIX}," \
		-e "s,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR}," \
		${FILESDIR}/pearpc.sh > ${WRKSRC}/pearpc.sh
	${INSTALL_SCRIPT} ${WRKSRC}/pearpc.sh ${PREFIX}/bin/pearpc
	${INSTALL_PROGRAM} ${WRKSRC}/src/ppc ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/ppccfg.example ${EGDIR}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
