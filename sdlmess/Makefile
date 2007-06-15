# $NetBSD: Makefile,v 1.1.1.1 2007/06/15 22:06:10 thomasklausner Exp $
#

DISTNAME=		sdlmess0116
PKGNAME=		sdlmess-0.116
CATEGORIES=		emulators
MASTER_SITES=		http://rbelmont.mameworld.info/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://rbelmont.mameworld.info/?page_id=163
COMMENT=		Multi Emulator Super System, SDL port

CONFLICTS=		xmess-[0-9]*

RESTRICTED=		selling is not allowed
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_TOOLS+=		gmake
#UNLIMIT_RESOURCES=	datasize
MAKE_FILE=		makefile.sdl
LICENSE=		mame-license

.if ${MACHINE_ARCH:Mi386}
X86_MIPS3_DRC = 1
X86_PPC_DRC = 1
#PKG_DEFS+=	-DX86_ASM
.else
X86_MIPS3_DRC =
X86_PPC_DRC =
.endif
.if ${MACHINE_ARCH:Mppc}
PKG_DEFS+=	-DPPC_ASM
.endif

.  include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN:Mlittle}
PKG_DEFS+=	-DLSB_FIRST
.endif

PKG_DEFS+=	-DSDLMAME_NO64BITIO
# XXX: PTR64
MAKE_FLAGS+=	PKG_DEFS=${PKG_DEFS:Q}
MAKE_FLAGS+=	X86_MPIS3_DRC=${X86_MIPS3_DRC:Q}
MAKE_FLAGS+=	X86_PPC_DRC=${X86_PPC_DRC:Q}

INSTALLATION_DIRS=	bin share/doc/mess/sysinfo share/mess/artwork \
			share/mess/hash

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/imgtool ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mess ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/artwork/* ${PREFIX}/share/mess/artwork
	${INSTALL_DATA} ${WRKSRC}/hash/* ${PREFIX}/share/mess/hash
	${INSTALL_DATA} ${WRKSRC}/sysinfo.htm ${PREFIX}/share/doc/mess
	${INSTALL_DATA} ${WRKSRC}/sysinfo/* ${PREFIX}/share/doc/mess/sysinfo

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
