# $NetBSD: Makefile,v 1.1.1.1 2007/07/31 18:18:57 noud4 Exp $
#

DISTNAME=		qemu-neo1973
PKGNAME=		qemu-neo1973-1.1.1
CATEGORIES=		emulators
MASTER_SITES=		http://wiki.openmoko.org/

MAINTAINER=		noud4@home.nl
HOMEPAGE=		http://wiki.openmoko.org/wiki/OpenMoko_under_QEMU
COMMENT=		QEMU OpenMoko neo1973 phone emulator

CONFLICTS+=		qemu-bin-[0-9]*
NOT_FOR_PLATFORM=	NetBSD-1.[0-6]*-*

USE_TOOLS+=		gmake perl:build
USE_TOOLS+=		tar gzip
HAS_CONFIGURE=		yes

BUILD_DEPENDS+=		subversion-base>=1.4.2:../../devel/subversion-base
DEPENDS+=		wget>=1.10.2:../../net/wget
DEPENDS+=		lynx>=2.8.5.5:../../www/lynx
DEPENDS+=		python24>=2.4.3:../../lang/python24
DEPENDS+=		netpbm>=10.34:../../graphics/netpbm
BUILD_DEPENDS+=		texi2html-[0-9]*:../../textproc/texi2html

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=		3.0

.if !empty(MACHINE_PLATFORM:MNetBSD-4*)
USE_PKGSRC_GCC= 	yes
.endif

CONFIGURE_ENV+=		PKGMANDIR=${PKGMANDIR}
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--interp-prefix=${PREFIX:Q}/share/qemu
CONFIGURE_ARGS+=	--target-list=arm-softmmu

SUBST_CLASSES+=		snd
SUBST_STAGE.snd=	post-patch
SUBST_FILES.snd=	audio/ossaudio.c
SUBST_SED.snd=		-e s,/dev/dsp,${DEVOSSAUDIO:Q},g
SUBST_MESSAGE.snd=	Fixing hardcoded audio device.

SUBST_CLASSES+=		smbd
SUBST_STAGE.smbd=	post-patch
SUBST_FILES.smbd=	vl.c
SUBST_SED.smbd=		-e s,/usr/sbin/smbd,${PREFIX:Q}/sbin/smbd,g
SUBST_MESSAGE.smbd=	Fixing hardcoded paths.

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	post-patch
SUBST_FILES.perl=	openmoko/Makefile openmoko/flash.sh
SUBST_SED.perl=		-e s,@@PREFIX@@,${PREFIX:Q},g
SUBST_MESSAGE.perl=	Fixing hardcoded paths.

REPLACE_PERL+=		texi2pod.pl

# Remove -march/-mcpu from CFLAGS, otherwise it will fail
# to build in the SSE code.
BUILDLINK_TRANSFORM+=	rm-optarg:-march rm-optarg:-mcpu

# Does not build with the stack protector
.if ${OPSYS} == "DragonFly"
CFLAGS+=		-fno-stack-protector
.endif

SUBDIR=		qemu-neo1973
WRKSRC=		${WRKDIR}/${SUBDIR}
NO_CHECKSUM=	yes

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-4*)
CONFIGURE_ARGS+=	--disable-gcc-check
.endif

do-fetch:
	if [ ! -f ${DISTDIR}/${SUBDIR:Q}.tar.gz ]; then \
		${MKDIR} -p ${DISTDIR}/${SUBDIR}; \
		cd ${DISTDIR}; svn checkout https://svn.openmoko.org/trunk/src/host/qemu-neo1973; \
		cd ${DISTDIR}; tar -cf ${SUBDIR}.tar ${SUBDIR};gzip ${SUBDIR}.tar; \
		${RM} -r ${DISTDIR}/${SUBDIR}; \
	fi
	# latest fetch: revision 2587.

post-install:
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/doc/qemu

	${INSTALL_MAN} ${WRKSRC}/qemu.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/qemu-img.1 ${PREFIX}/${PKGMANDIR}/man1

	${INSTALL_DATA_DIR} ${PREFIX:Q}/emul/neo1973/openmoko
	${INSTALL_DATA} ${WRKSRC}/openmoko/Makefile ${PREFIX:Q}/emul/neo1973/openmoko
	${INSTALL_SCRIPT} ${WRKSRC}/openmoko/download.sh ${PREFIX:Q}/emul/neo1973/openmoko
	${INSTALL_DATA} ${WRKSRC}/openmoko/env ${PREFIX:Q}/emul/neo1973/openmoko
	${INSTALL_SCRIPT} ${WRKSRC}/openmoko/flash.sh ${PREFIX:Q}/emul/neo1973/openmoko

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# ln -s /usr/pkg/bin/python2.4  /usr/pkg/bin/python
