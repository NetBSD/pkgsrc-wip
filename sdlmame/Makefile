# $NetBSD: Makefile,v 1.13 2008/06/30 12:02:57 thomasklausner Exp $
#

# Don't update to 0.XXXuN, those are development snapshots.
DISTNAME=		sdlmame0125
PKGNAME=		sdlmame-0.125
CATEGORIES=		emulators
MASTER_SITES=		http://rbelmont.mameworld.info/
EXTRACT_SUFX=		.zip

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://rbelmont.mameworld.info/?page_id=163
COMMENT=		Multiple Arcade Machine Emulator, SDL port

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		xmame-[0-9]*

RESTRICTED=		selling is not allowed
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_TOOLS+=		gmake
UNLIMIT_RESOURCES=	datasize
MAKE_FILE=		makefile
LICENSE=		mame-license

.if ${MACHINE_ARCH:Mi386}
MAKE_FLAGS+=	X86_MIPS3_DRC=1
MAKE_FLAGS+=	X86_PPC_DRC=1
#MAKE_FLAGS+=	X86_ASM=1
.else
MAKE_FLAGS+=	X86_MIPS3_DRC=
MAKE_FLAGS+=	X86_PPC_DRC=
.endif
# XXX: PTR64
.if ${MACHINE_ARCH:Mx86_64}
MAKE_FLAGS+=	PTR64=true
# XXX: FORCE_DRC_C_BACKEND?
.endif

.  include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN:Mbig}
MAKE_FLAGS+=	BIGENDIAN=true
.endif

MAKE_FLAGS+=	SDLMAME_NO64BITIO=true

# Pragma once is not needed, and creates warnings/errors on gcc
SUBST_CLASSES+=		pragma
SUBST_STAGE.pragma=	pre-configure
SUBST_FILES.pragma=	src/*.h src/*/*.h
SUBST_SED.pragma=	-e "s|\#pragma once||g"

DOCDIR=			share/doc/sdlmame
INSTALLATION_DIRS=	bin ${DOCDIR}

do-install:
	set -e; \
	for prg in chdman jedutil mame romcmp; \
	do \
		${INSTALL_PROGRAM} ${WRKSRC}/"$$prg" ${DESTDIR}${PREFIX}/bin; \
	done
	${INSTALL_DATA} ${WRKSRC}/SDLMAME.txt ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/license.txt ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/mame.txt ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/windows.txt ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
