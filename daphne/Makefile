# $NetBSD: Makefile,v 1.8 2006/07/10 20:00:48 dillo Exp $
#

DISTNAME=		${PKGNAME_NOREV}-src
PKGNAME=		daphne-0.99.7c
CATEGORIES=		emulators
MASTER_SITES=		http://daphne.rulecity.com/download/
MASTER_SITES+=		http://daphne.rulecity.com/download/old/

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://daphne.rulecity.com/
COMMENT=		Emulator for Laserdisc arcade games

WRKSRC=			${WRKDIR}/daphne
USE_TOOLS+=		gmake
USE_LANGUAGES+=		c++
GNU_CONFIGURE=		YES
CONFIGURE_DIRS=		src/vldp2
BUILD_DIRS=		src

MAKE_ENV+=		DATA_DIR=${LOCALBASE:Q}/share/daphne
MAKE_ENV+=		LIB_DIR=${LOCALBASE:Q}/lib/daphne
.if ${MACHINE_ARCH} == "i386"
MAKE_ENV+=		USE_MMX_RGB2YUV=1
MAKE_ENV+=		PFLAGS="-DNATIVE_CPU_X86 -DMMX_RGB2YUV"
.endif

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"

post-extract:
	${CP} ${WRKSRC:Q}/src/Makefile.vars.linux_x86 ${WRKSRC:Q}/src/Makefile.vars

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/daphne ${PREFIX:Q}/bin
	${INSTALL_DATA_DIR} ${PREFIX:Q}/lib/daphne
	${INSTALL_DATA} ${WRKSRC:Q}/libvldp2.so ${PREFIX:Q}/lib/daphne
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/daphne
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/daphne/pics
	set -e;								\
	for f in ${WRKSRC:Q}/pics/*.bmp; do				\
		${INSTALL_DATA} "$$f" ${PREFIX:Q}/share/daphne/pics/;	\
	done
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/daphne/sound
	set -e;								\
	for f in ${WRKSRC:Q}/sound/*.wav; do				\
		${INSTALL_DATA} "$$f" ${PREFIX:Q}/share/daphne/sound/;	\
	done

.include "../../mk/bsd.pkg.mk"
