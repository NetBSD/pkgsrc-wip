# $NetBSD: Makefile,v 1.0 2023/12/11 11:20:00 dkazankov Exp $

.include "version.mk"
PKGNAME=gprbuild-${GPRBUILD_VERSION}

CATEGORIES=	devel
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/gprbuild
COMMENT=	GPRbuild build system
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c ada

.include "../../mk/bsd.prefs.mk"

DISTNAME=	${PKGNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	xmlada-${GPRBUILD_VERSION}${EXTRACT_SUFX}
DISTFILES+=	gprconfig_kb-${GPRBUILD_VERSION}${EXTRACT_SUFX}
GITHUB_TAG=	v${GPRBUILD_VERSION}
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}

SITES.xmlada-${GPRBUILD_VERSION}${EXTRACT_SUFX}=	-${MASTER_SITE_GITHUB:=AdaCore/}xmlada/archive/${GITHUB_TAG}${EXTRACT_SUFX}
SITES.gprconfig_kb-${GPRBUILD_VERSION}${EXTRACT_SUFX}=	-${MASTER_SITE_GITHUB:=AdaCore/}gprconfig_kb/archive/${GITHUB_TAG}${EXTRACT_SUFX}

USE_TOOLS+=	gmake patch

HAS_CONFIGURE=	yes

GCC_REQD+=	13
.include "../../wip/gcc13-gnat/gcc.mk"

OBJDIR=		${WRKDIR}/build
BOOTSTRAPDIR=	${WRKDIR}/bootstrap
CGPRDIR=	${WRKDIR}/.home

PRECONFIGURE_ENV=	${CONFIGURE_ENV}
POSTCONFIGURE_ENV=	${CONFIGURE_ENV}

PRECONFIGURE_ENV+=	CC=${CC}
PRECONFIGURE_ENV+=	CFLAGS=${CFLAGS:M:Q}
PRECONFIGURE_ENV+=	GNATMAKE=${GMKPATH}

CONFIGURE_DIRS=		${OBJDIR}
CONFIG_SHELL=		${MAKE_PROGRAM} -f
CONFIGURE_SCRIPT=	${WRKSRC}/Makefile
CONFIGURE_ARGS=		setup
CONFIGURE_ARGS+=	prefix=${DESTDIR}${PREFIX}
CONFIGURE_ARGS+=	SOURCE_DIR=${WRKSRC}

BUILD_DIRS=		${OBJDIR}
MAKE_FILE=		${WRKSRC}/Makefile
BUILD_MAKE_FLAGS=	GPRBUILD_OPTIONS='--config=${CGPRDIR}/buildlink.cgpr -aP ${WRKDIR}/.buildlink/share/gpr'

INSTALL_DIRS=		${OBJDIR}
INSTALL_MAKE_FLAGS=	GPRBUILD_OPTIONS='--config=${CGPRDIR}/buildlink.cgpr -aP ${WRKDIR}/.buildlink/share/gpr'
INSTALL_MAKE_FLAGS+=	GPRINSTALL_OPTIONS='--config=${CGPRDIR}/buildlink.cgpr -aP ${WRKDIR}/.buildlink/share/gpr'

SUBST_CLASSES+=		buildlink
SUBST_STAGE.buildlink=	pre-configure
SUBST_FILES.buildlink=	../.home/buildlink.cgpr
SUBST_MESSAGE.buildlink=Set work directory path in config project
SUBST_SED.buildlink=	-e 's,@WRKDIR@,${WRKDIR},g'

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} bin libexec share \( -type f -or -type l \) -print | ${SORT};

post-patch:
	${RUN} cd ${PKGDIR} \
	&& ${PATCH} -d ${WRKDIR}/xmlada-${GPRBUILD_VERSION} -E -p0 -F0 <files/patch-Makefile.in
.if ${MACHINE_PLATFORM:MNetBSD-*-*}
	${RUN} cd ${PKGDIR} \
	&& ${PATCH} -d ${WRKSRC} -E -p0 -F0 <files/patch-gpr_src_put_resource_usage__unix.adb
.endif
	${RUN} ${CP} ${PKGDIR}/files/buildlink.cgpr ${CGPRDIR}/

pre-configure:
	${RUN} ${MKDIR} ${BOOTSTRAPDIR}
	${RUN} cd ${BOOTSTRAPDIR} \
	&& env ${PRECONFIGURE_ENV} \
	${SHELL} ${WRKSRC}/bootstrap.sh \
	    --prefix=${WRKDIR}/.buildlink \
	    --srcdir=${WRKSRC} \
	    --with-xmlada=${WRKDIR}/xmlada-${GPRBUILD_VERSION} \
	    --with-kb=${WRKDIR}/gprconfig_kb-${GPRBUILD_VERSION}
	${RUN} ${MKDIR} ${OBJDIR}

post-configure:
	${RUN} cd ${WRKDIR}/xmlada-${GPRBUILD_VERSION} \
	&& set -x ; env ${POSTCONFIGURE_ENV} \
	./configure \
	    --prefix=${WRKDIR}/.buildlink \
	&& set -x ; env ${MAKE_ENV} \
	${MAKE_PROGRAM} all install GPROPTS='--config=${CGPRDIR}/buildlink.cgpr'

.include "../../mk/bsd.pkg.mk"
