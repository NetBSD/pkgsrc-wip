# $NetBSD: Makefile,v 1.1.1.1 2004/06/24 15:15:32 dillo Exp $
#

DISTNAME=		${PKGNAME_NOREV}-src
PKGNAME=		daphne-0.99.6
CATEGORIES=		emulators
MASTER_SITES=		http://daphne.rulecity.com/download/

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://daphne.rulecity.com/
COMMENT=		Emulator for Laserdisc arcade games

WRKSRC=			${WRKDIR}/daphne/src
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		#defined
CONFIGURE_DIRS=		${WRKSRC}/vldp2

MAKE_ENV+=		DATA_DIR=${LOCALBASE}/share/daphne
MAKE_ENV+=		LIB_DIR=${LOCALBASE}/lib/daphne
.if ${MACHINE_ARCH} == "i386"
MAKE_ENV+=		USE_MMX_RGB2YUV=1
MAKE_ENV+=		PFLAGS="-DNATIVE_CPU_X86 -DMMX_RGB2YUV"
.endif

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"

post-extract:
	${CP} ${WRKSRC}/Makefile.vars.linux_x86 ${WRKSRC}/Makefile.vars

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../daphne ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/lib/daphne
	${INSTALL_DATA} ${WRKSRC}/../libvldp2.so ${PREFIX}/lib/daphne
	${INSTALL_DATA_DIR} ${PREFIX}/share/daphne
	${INSTALL_DATA_DIR} ${PREFIX}/share/daphne/pics
	for f in ${WRKSRC}/../pics/*.bmp; \
	do \
		${INSTALL_DATA} $$f ${PREFIX}/share/daphne/pics; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/daphne/sound
	for f in ${WRKSRC}/../sound/*.wav; \
	do \
		${INSTALL_DATA} $$f ${PREFIX}/share/daphne/sound; \
	done

.include "../../mk/bsd.pkg.mk"
