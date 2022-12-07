# $NetBSD$

DISTNAME=	mm-0.96.0.15
CATEGORIES=	mail
MASTER_SITES=	https://sehnsucht.multics.org/pub/pkgsrc/distfiles/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://www.kermitproject.org/mm/
COMMENT=	UNIX reimplementation of the TOPS-20 MM program
LICENSE=	mit

ONLY_FOR_PLATFORM+=	*-*-i386
MKPIE_SUPPORTED=	no

MAKE_FLAGS+=	OPT=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	LOCLIB=${DESTDIR}${PREFIX}/lib/mm

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Replacing hard-coded paths.
SUBST_FILES.paths+=	config.h pathnames.h
SUBST_FILES.paths+=	regex-0.12/configure
SUBST_SED.paths=	-e 's|/usr/local|${PREFIX}|'

SETUID_ROOT_PERMS=	${REAL_ROOT_USER} daemon 2551
SPECIAL_PERMS+=		lib/mm/movemail

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS:M*BSD} || ${OPSYS} == Linux
TARGET:=	${LOWER_OPSYS}
.elif ${OPSYS} == Darwin
TARGET:=	macosx
.elif ${OPSYS} == SunOS
TARGET:=	solaris
.endif

INSTALLATION_DIRS+=	bin lib

WRKSRC=	${WRKDIR}/mm/mm

post-extract:
	${RUN}${CHMOD} +x ${WRKSRC}/regex-0.12/configure


.if ${OPSYS} != NetBSD
pre-build:
	${RUN}cd ${WRKDIR}/mm/ccmd && ${SETENV} ${MAKE_ENV}	\
  	  ${MAKE_PROGRAM} ${TARGET}
.endif

do-build:
	${RUN}cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}		\
	  ${MAKE_PROGRAM} ${TARGET}

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sys-prof			\
	  ${DESTDIR}/${PREFIX}/bin/mm-sysprof

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
