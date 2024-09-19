# $NetBSD$

GITHUB_PROJECT=	ioq3
GITHUB_TAG=	05180e32dcfb9a4552e1b9652b56127248a9950c
DISTNAME=	${GITHUB_TAG}
PKGNAME=	ioquake3-20200526
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=ioquake/}
DIST_SUBDIR=	${GITHUB_PROJECT}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ioquake3.org/
COMMENT=	Open source Quake 3 distribution
LICENSE=	gnu-gpl-v2

WRKSRC=	${WRKDIR}/ioq3-${GITHUB_TAG}

USE_TOOLS+=	gmake pkg-config
BUILD_TARGET=	release
MAKE_FLAGS+=	USE_INTERNAL_LIBS=0

NOT_PAX_MPROTECT_SAFE=	lib/ioquake3/ioquake3.${QUAKE_ARCH}

INSTALLATION_DIRS+=	bin lib/ioquake3
SUBST_CLASSES+=		scripts
SUBST_STAGE.scripts=	pre-configure
SUBST_MESSAGE.scripts=	Setting scripts prefix and architecture.
SUBST_FILES.scripts=	ioq3ded.sh ioquake3.sh
SUBST_VARS.scripts=	PREFIX QUAKE_ARCH

post-extract:
	cp ${FILESDIR}/ioquake3.sh ${WRKSRC}
	cp ${FILESDIR}/ioq3ded.sh ${WRKSRC}

do-install:
	cd ${WRKSRC} && \
		${GMAKE} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} \
			COPYDIR=${DESTDIR}${PREFIX}/lib/ioquake3 copyfiles
	${INSTALL_SCRIPT} ${WRKSRC}/ioquake3.sh ${DESTDIR}${PREFIX}/bin/ioquake3
	${INSTALL_SCRIPT} ${WRKSRC}/ioq3ded.sh ${DESTDIR}${PREFIX}/bin/ioq3ded

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && ${MACHINE_CPU:U} == "arm"
QUAKE_ARCH!=	uname -m
.else
QUAKE_ARCH=	${MACHINE_ARCH:i386=x86}
.endif

PLIST_SUBST+=	QUAKE_ARCH=${QUAKE_ARCH:Q}

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/opusfile/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
