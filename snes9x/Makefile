# $NetBSD: Makefile,v 1.6 2006/03/09 21:02:15 jlamwww Exp $
#

DISTNAME=		snes9x-${S9X_VER}-src
PKGNAME=		${DISTNAME:S/-src//}
CATEGORIES=		emulators
MASTER_SITES=		http://www.lysator.liu.se/snes9x/${S9X_VER}/	\
			http://files.ipherswipsite.com/snes9x/		\
			http://www.zophar.net/Files/			\
			http://vincent.grigorieff.free.fr/snes9x/
MAINTAINER=		jmcneill@NetBSD.org
HOMEPAGE=		http://www.snes9x.com/
COMMENT=		Super Nintendo Entertainment System (SNES) emulator

WRKSRC=			${WRKDIR}/${DISTNAME}/snes9x
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
PTHREAD_OPTS+=		require
INSTALLATION_DIRS=	bin

S9X_VER=		1.43

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/offsets ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/snes9x ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/snes9x
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/documentation/Le_FAQ_de_Snes9x.txt ${PREFIX}/share/doc/snes9x
	${INSTALL_DATA} ${WRKSRC}/changes.txt ${PREFIX}/share/doc/snes9x
	${INSTALL_DATA} ${WRKSRC}/copyright.h ${PREFIX}/share/doc/snes9x
	${INSTALL_DATA} ${WRKSRC}/hardware.txt ${PREFIX}/share/doc/snes9x
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/license.txt ${PREFIX}/share/doc/snes9x
	${INSTALL_DATA} ${WRKSRC}/doc/porting.txt ${PREFIX}/share/doc/snes9x
	${INSTALL_DATA} ${WRKSRC}/problems.txt ${PREFIX}/share/doc/snes9x
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/documentation/readme.txt ${PREFIX}/share/doc/snes9x
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/readme.unix ${PREFIX}/share/doc/snes9x

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.snes9x
.if ${MACHINE_ARCH} == "i386"
PKG_SUPPORTED_OPTIONS+=	mmx
.endif

.include "../../mk/bsd.options.mk"

MAKE_ENV+=	THREAD_SOUND=1
.if ${MACHINE_ARCH} == "i386"
MAKE_ENV+=	USING_I386=1
.if ${OBJECT_FMT} == "a.out"
MAKE_ENV+=	FILEFORMAT=aoutb
MAKE_ENV+=	_ASM_UNDERBARS=1
.else
MAKE_ENV+=	FILEFORMAT=elf
.endif
MAKE_ENV+=	ZSNESFX=1
MAKE_ENV+=	ZSNESC4=1
MAKE_ENV+=	ASMCPU=1
.if !empty(PKG_OPTIONS:Mmmx)
MAKE_ENV+=	ASMKREED=1
.endif
.endif

.if ${MACHINE_ARCH} == "i386"
BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm
CONFIGURE_ARGS+=	--with-assembler
.endif

.if exists(${X11BASE}/lib/libXxf86dga.a)
MAKE_ENV+=	NETBSD_USE_DGA=1
.endif

.if exists(/usr/include/usb.h) || exists(/usr/include/usbhid.h)
MAKE_ENV+=	USBJOY=1
.if exists(/usr/include/usbhid.h)
MAKE_ENV+=	USBHID_H=1
.endif
.endif

.include "../../devel/zlib/buildlink3.mk"
#.include "../../graphics/png/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
