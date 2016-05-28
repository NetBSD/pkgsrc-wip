# $NetBSD: Makefile,v 1.10 2014/02/11 21:04:07 noud4 Exp $
#

DISTNAME=		qemu-neo1973-4412
CATEGORIES=		emulators
MASTER_SITES=		http://wiki.openmoko.org/
SVN_REPOSITORY=		https://svn.openmoko.org/trunk/src/host/qemu-neo1973
#NO_CHECKSUM=		yes

MAINTAINER=		noud4@users.sourceforge.net
HOMEPAGE=		http://wiki.openmoko.org/wiki/OpenMoko_under_QEMU
COMMENT=		Qemu OpenMoko Neo1973 phone emulator

BROKEN=			please convert this to svn-package.mk
NOT_FOR_PLATFORM=	NetBSD-1.[0-6]*-*


USE_TOOLS+=		gmake perl:build
USE_TOOLS+=		tar gzip
HAS_CONFIGURE=		yes

BUILD_DEPENDS+=		subversion-base>=1.4.2:../../devel/subversion-base
DEPENDS+=		wget>=1.10.2:../../net/wget
DEPENDS+=		lynx>=2.8.5.5:../../www/lynx
DEPENDS+=		netpbm>=10.34:../../graphics/netpbm
BUILD_DEPENDS+=		texi2html-[0-9]*:../../textproc/texi2html

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=		3.0

.if !empty(MACHINE_PLATFORM:MNetBSD-4*)
USE_PKGSRC_GCC=	yes
.endif

NEO1973_PREFIX=		${PREFIX}/${PKGBASE}
PLIST_SUBST+=		NEO1973_PREFIX=${PKGBASE}
MESSAGE_SUBST+=		NEO1973_PREFIX=${NEO1973_PREFIX}

CONFIGURE_ARGS+=	--prefix=${NEO1973_PREFIX:Q}
CONFIGURE_ARGS+=	--interp-prefix=${NEO1973_PREFIX:Q}/share/qemu
CONFIGURE_ARGS+=	--target-list=arm-softmmu
CONFIGURE_ENV+=		PKGMANDIR=/${PKGMANDIR}
.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M4.99.[0-9]*)
CONFIGURE_ENV+=		FORCE_AIO="yes"
.endif

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

SUBST_CLASSES+=		moko
SUBST_STAGE.moko=	post-patch
SUBST_FILES.moko=	openmoko/Makefile openmoko/flash.sh
SUBST_SED.moko=		-e s,@@PREFIX@@,${PREFIX:Q},g
SUBST_MESSAGE.moko=	Fixing OpenMoko paths.

REPLACE_PERL+=		texi2pod.pl

# Remove -march/-mcpu from CFLAGS, otherwise it will fail
# to build in the SSE code.
BUILDLINK_TRANSFORM+=	rm-optarg:-march rm-optarg:-mcpu

# Does not build with the stack protector
.if ${OPSYS} == "DragonFly"
CFLAGS+=		-fno-stack-protector
.endif

SUBDIR=		${PKGNAME}
WRKSRC=		${WRKDIR}/${SUBDIR}

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-4*)
CONFIGURE_ARGS+=	--disable-gcc-check
.endif

do-fetch:
	if [ ! -f ${DISTDIR}/${SUBDIR:Q}.tar.gz ]; then \
		cd ${DISTDIR:Q}; \
		svn export -r ${PKGVERSION} ${SVN_REPOSITORY} ${SUBDIR:Q}; \
		tar -czf ${SUBDIR:Q}.tar.gz ${SUBDIR:Q}; \
		${RM} -r ${DISTDIR}/${SUBDIR:Q}; \
	fi

post-install:
	${MV} ${NEO1973_PREFIX:Q}/bin/qemu-system-arm ${NEO1973_PREFIX:Q}/bin/qemu-neo1973
	${MV} ${NEO1973_PREFIX:Q}/bin/qemu-img ${NEO1973_PREFIX:Q}/bin/qemu-neo1973-img
	${LN} -sf ../${PKGBASE}/bin/qemu-neo1973 ${PREFIX:Q}/bin/qemu-neo1973

	${INSTALL_DATA_DIR} ${NEO1973_PREFIX:Q}/libexec/openmoko/
	${INSTALL_DATA} ${WRKSRC}/openmoko/Makefile ${NEO1973_PREFIX:Q}/libexec/openmoko
	${INSTALL_SCRIPT} ${WRKSRC}/openmoko/download.sh ${NEO1973_PREFIX:Q}/libexec/openmoko
	${INSTALL_DATA} ${WRKSRC}/openmoko/env ${NEO1973_PREFIX:Q}/libexec/openmoko
	${INSTALL_SCRIPT} ${WRKSRC}/openmoko/flash.sh ${NEO1973_PREFIX:Q}/libexec/openmoko

.include "../../devel/SDL/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# ln -s /usr/pkg/bin/python2.X  /usr/pkg/bin/python
# cd /usr/pkg/qemu-neo1973/libexec; ../bin/qemu-neo1973  openmoko/openmoko-flash.image -kernel openmoko/openmoko-kernel.bin -show-cursor -monitor stdio -M gta01 -m 130 -mtdblock openmoko/openmoko-flash.image -kernel openmoko/openmoko-kernel.bin -usb -usbdevice host:07a6:8511 -show-cursor -monitor stdio -usbdevice keyboard -serial telnet:localhost:1200,server
