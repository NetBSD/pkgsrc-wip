# $NetBSD: Makefile,v 1.5 2006/05/04 15:53:50 hubertf Exp $
#

DISTNAME=		qemu-0.8.0
PKGNAME=		qemu-qvm86-0.8.0
CATEGORIES=		emulators
MASTER_SITES=		http://fabrice.bellard.free.fr/qemu/

MAINTAINER=		tnn+nbsd@nygren.pp.se
HOMEPAGE=		http://www.qemu.org/
COMMENT=		CPU emulator using dynamic translation (qvm86 version)

CONFLICTS+=		qemu-*
ONLY_FOR_PLATFORM=	NetBSD-[3-9]*-i386

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes

GCC_REQD+=		3.0

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--interp-prefix=${PREFIX}/share/qemu

SUBST_CLASSES+=		snd smbd
SUBST_STAGE.snd=	post-patch
SUBST_FILES.snd=	audio/ossaudio.c
SUBST_SED.snd=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_MESSAGE.snd=	Fixing hardcoded audio device.
SUBST_STAGE.smbd=	post-patch
SUBST_FILES.smbd=	vl.c
SUBST_SED.smbd=		-e "s,/usr/sbin/smbd,${PREFIX}/sbin/smbd,g"
SUBST_MESSAGE.smbd=	Fixing hardcoded paths.

# Remove -march/-mcpu from CFLAGS, otherwise it will fail
# to build in the SSE code.
BUILDLINK_TRANSFORM+=	rm-optarg:-march rm-optarg:-mcpu

.include "../../mk/compiler.mk"

# qemu cannot yet use gcc 4, see the faq/mailing lists
# (hint: use gcc_select on darwin/macos to choose gcc 3.3 instead)
.if !empty(CC_VERSION:Mgcc-4*)
PKG_FAIL_REASON+=	"${PKGNAME} cannot use ${CC_VERSION}"
.endif

.if !exists(/usr/src/sys/sys/systm.h) && \
!exists(${NETBSDSRCDIR}/sys/sys/systm.h) && \
!exists(${BSDSRCDIR}/sys/sys/systm.h)
PKG_FAIL_REASON+=	"Please set NETBSDSRCDIR in mk.conf"
.endif

CVSROOT=	:pserver:anonymous:@cvs.savannah.nongnu.org:/sources/qvm86

post-extract:
	cd ${WRKDIR}/${DISTNAME} && \
	${SETENV} CVS_PASSFILE=${WRKDIR}/.cvspass cvs -d ${CVSROOT} login && \
	${SETENV} CVS_PASSFILE=${WRKDIR}/.cvspass cvs -Q -d ${CVSROOT} \
	co -d kqemu qvm86 && \
	${CP} ${FILESDIR}/Makefile.NetBSD ${WRKDIR}/${DISTNAME}/kqemu && \
	${CP} ${FILESDIR}/qvm86-netbsd.[ch] ${WRKDIR}/${DISTNAME}/kqemu

post-install:
	${INSTALL_DATA} ${FILESDIR}/Makefile.multinode-NetBSD \
		${PREFIX}/share/doc/qemu
	${INSTALL_DATA} ${FILESDIR}/qvm86.sh \
		${PREFIX}/share/qemu
	${INSTALL_LIB_DIR} ${PREFIX}/lib/qemu
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/kqemu/qvm86.o \
		${PREFIX}/lib/qemu

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
