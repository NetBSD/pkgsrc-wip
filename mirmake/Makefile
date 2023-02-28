# $NetBSD$

DISTNAME=	mirmake_20141220.orig
PKGNAME=	mirmake-20141220
CATEGORIES=	devel
MASTER_SITES=	http://www.mirbsd.org/MirOS/dist/mir/make/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	http://www.mirbsd.org/man1/make.htm
COMMENT=	Portable version of MirBSD make(1) and associated tools
LICENSE=	modified-bsd AND isc AND miros

.if exists(/bin/ksh)
KSH=		/bin/ksh
.else
TOOL_DEPENDS+=	mksh-[0-9]*:../../shells/mksh
KSH=		${PREFIX}/bin/mksh
.endif

UID=	`id -un`
GID=	`id -gn`

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	Build.sh
SUBST_VARS.paths=	PREFIX
SUBST_MESSAGE.paths=	Include pkgsrc PREFIX in searched paths.

.include "../../mk/bsd.prefs.mk"

# build script accepts a number of arguments 
BUILD_ARGS=	${OPSYS}
BUILD_ARGS+=	${PREFIX}
BUILD_ARGS+=	${PKGMANDIR}/man
BUILD_ARGS+=	mbmake
BUILD_ARGS+=	""
BUILD_ARGS+=	""
BUILD_ARGS+=	""
BUILD_ARGS+=	${KSH}
BUILD_ARGS+=	${UID}:${GID}

WRKSRC=		${WRKDIR}/mirmake

MAKE_ENV+=	LIBS=${LIBS:Q}
MAKE_ENV+=	OVERRIDE_MKSH=${KSH}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}			\
		${SH} ${WRKSRC}/Build.sh ${BUILD_ARGS}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV}	\
		${SH} ${WRKSRC}/Install.sh

.if ${OPSYS} == "Linux"
.  include "../../devel/libbsd/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
