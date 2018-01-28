# $NetBSD: Makefile,v 1.14 2012/12/12 10:44:37 thomasklausner Exp $
#

DISTNAME=		${PKGNAME_NOREV}-src
PKGNAME=		daphne-0.99.7c
CATEGORIES=		emulators
MASTER_SITES=		http://daphne.rulecity.com/download/
MASTER_SITES+=		http://daphne.rulecity.com/download/old/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.daphne-emu.com/site3/
COMMENT=		Emulator for Laserdisc arcade games

WRKSRC=			${WRKDIR}/daphne
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
CONFIGURE_DIRS=		src/vldp2
BUILD_DIRS=		src

MAKE_ENV+=		DATA_DIR=${LOCALBASE}/share/daphne
MAKE_ENV+=		LIB_DIR=${LOCALBASE}/lib/daphne
.if ${MACHINE_ARCH} == "i386"
MAKE_ENV+=		USE_MMX_RGB2YUV=1
MAKE_ENV+=		PFLAGS="-DNATIVE_CPU_X86 -DMMX_RGB2YUV"
.endif

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"

post-extract:
	${CP} ${WRKSRC}/src/Makefile.vars.linux_x86 ${WRKSRC}/src/Makefile.vars

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/daphne ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/daphne
	${INSTALL_DATA} ${WRKSRC}/libvldp2.so ${DESTDIR}${PREFIX}/lib/daphne
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/daphne
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/daphne/pics
	set -e;								\
	for f in ${WRKSRC}/pics/*.bmp; do				\
		${INSTALL_DATA} "$$f" ${DESTDIR}${PREFIX}/share/daphne/pics/;	\
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/daphne/sound
	set -e;								\
	for f in ${WRKSRC}/sound/*.wav ${WRKSRC}/sound/*.ogg; do	\
		${INSTALL_DATA} "$$f" ${DESTDIR}${PREFIX}/share/daphne/sound/;	\
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/daphne
	${INSTALL_DATA} ${WRKSRC}/doc/docs.html \
		${DESTDIR}${PREFIX}/share/doc/daphne/index.html
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/daphne/graphics
	set -e;								\
	for f in ${WRKSRC}/doc/docs_files/*.[Jj][Pp][Gg]; do		\
		n=`basename "$$f"`;					\
		n=`echo "$$n" | tr A-Z a-z`;				\
		${INSTALL_DATA} "$$f"					\
			${DESTDIR}${PREFIX}/share/doc/daphne/graphics/"$$n";	\
	done

.include "../../mk/bsd.pkg.mk"
