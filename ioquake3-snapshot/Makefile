# $NetBSD$

GITHUB_PROJECT=	ioq3
PKGNAME=	ioquake3-20170521
DISTNAME=	${GITHUB_TAG}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=ioquake/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	c65d2c2657fa6aecf498a5e1c20ffa706a80e818
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ioquake3.org/
COMMENT=	Open source Quake 3 distribution
LICENSE=	gnu-gpl-v2

WRKSRC=	${WRKDIR}/ioq3-${GITHUB_TAG}

USE_TOOLS+=	gmake
BUILD_TARGET=	release

NOT_PAX_MPROTECT_SAFE=	lib/ioquake3/ioquake3.${QUAKE_ARCH}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/ioquake3
	cd ${WRKSRC} && ${GMAKE} copyfiles COPYDIR=${DESTDIR}${PREFIX}/lib/ioquake3

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && ${MACHINE_CPU:U} == "arm"
QUAKE_ARCH!=	uname -m
.else
QUAKE_ARCH=	${MACHINE_ARCH:i386=x86}
.endif

PLIST_SUBST+=	QUAKE_ARCH=${QUAKE_ARCH:Q}

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
