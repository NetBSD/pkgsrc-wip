# $NetBSD: Makefile,v 1.0 2024/05/13 13:00:00 dkazankov Exp $

PKGNAME=	gnatcoll-db-25.0.0
DISTNAME=	gnatcoll-db-${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	gnatcoll-db
GITHUB_TAG=	v${PKGVERSION_NOREV}

HOMEPAGE=	https://github.com/AdaCore/gnatcoll-db
COMMENT=	The GNAT Components Collection (GNATcoll) - Database packages
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake grep

HAS_CONFIGURE=	yes

CHECK_PIE_SKIP+=	bin/*

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=	c ada

GCC_REQD+=	13

SUBST_CLASSES+=		fixver
SUBST_STAGE.fixver=	pre-configure
SUBST_FILES.fixver=	version_information
SUBST_SED.fixver=	-e 's,0.0,25.0,g'
SUBST_MESSAGE.fixver=	Fix version information

.include "options.mk"

CONFIG_SHELL_FLAGS+=	prefix=${DESTDIR}${PREFIX} BUILD=PROD
CONFIG_SHELL=		${MAKE_PROGRAM}
CONFIGURE_SCRIPT=	setup

# Makefile in gnatcoll_db2ada directory can build and install
# four different apps, but one at a time. So we need special
# build and install process for this directory

do-build:
.for _dir_ in ${BUILD_DIRS}
.  if ${_dir_} == "gnatcoll_db2ada"
.    if !empty(PKG_OPTIONS:Mgnatcoll_db2ada)
	${RUN}${_ULIMIT_CMD} \
	cd ${WRKSRC} && cd ${_dir_} && \
	${PKGSRC_SETENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} ${MAKE_JOBS} \
	${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} DB_BACKEND=db \
	-f ${MAKE_FILE} \
	${BUILD_TARGET}
.    endif
.    if !empty(PKG_OPTIONS:Mgnatcoll_postgres2ada)
	${RUN}${_ULIMIT_CMD} \
	cd ${WRKSRC} && cd ${_dir_} && \
	${PKGSRC_SETENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} ${MAKE_JOBS} \
	${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} DB_BACKEND=postgres \
	-f ${MAKE_FILE} \
	${BUILD_TARGET}
.    endif
.    if !empty(PKG_OPTIONS:Mgnatcoll_sqlite2ada)
	${RUN}${_ULIMIT_CMD} \
	cd ${WRKSRC} && cd ${_dir_} && \
	${PKGSRC_SETENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} ${MAKE_JOBS} \
	${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} DB_BACKEND=sqlite \
	-f ${MAKE_FILE} \
	${BUILD_TARGET}
.    endif
.    if !empty(PKG_OPTIONS:Mgnatcoll_all2ada)
	${RUN}${_ULIMIT_CMD} \
	cd ${WRKSRC} && cd ${_dir_} && \
	${PKGSRC_SETENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} ${MAKE_JOBS} \
	${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} DB_BACKEND=all \
	-f ${MAKE_FILE} \
	${BUILD_TARGET}
.    endif
.  else
	${RUN}${_ULIMIT_CMD} \
	cd ${WRKSRC} && cd ${_dir_} && \
	${BUILD_MAKE_CMD} ${BUILD_TARGET}
.  endif
.endfor

do-install:
.for _dir_ in ${INSTALL_DIRS}
.  if ${_dir_} == "gnatcoll_db2ada"
.    if !empty(PKG_OPTIONS:Mgnatcoll_db2ada)
	${RUN} ${_ULIMIT_CMD} \
	cd ${WRKSRC} && cd ${_dir_} && \
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} DB_BACKEND=db \
	-f ${MAKE_FILE} ${INSTALL_TARGET}
.    endif
.    if !empty(PKG_OPTIONS:Mgnatcoll_postgres2ada)
	${RUN} ${_ULIMIT_CMD} \
	cd ${WRKSRC} && cd ${_dir_} && \
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} DB_BACKEND=postgres \
	-f ${MAKE_FILE} ${INSTALL_TARGET}
.    endif
.    if !empty(PKG_OPTIONS:Mgnatcoll_sqlite2ada)
	${RUN} ${_ULIMIT_CMD} \
	cd ${WRKSRC} && cd ${_dir_} && \
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} DB_BACKEND=sqlite \
	-f ${MAKE_FILE} ${INSTALL_TARGET}
.    endif
.    if !empty(PKG_OPTIONS:Mgnatcoll_all2ada)
	${RUN} ${_ULIMIT_CMD} \
	cd ${WRKSRC} && cd ${_dir_} && \
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} DB_BACKEND=all \
	-f ${MAKE_FILE} ${INSTALL_TARGET}
.    endif
.  else
	${RUN} ${_ULIMIT_CMD} \
	cd ${WRKSRC} && cd ${_dir_} && \
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} \
	-f ${MAKE_FILE} ${INSTALL_TARGET}
.  endif
.endfor

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} bin include lib share \( -type f -or -type l \) -print | ${SORT};

.include "../../lang/gcc13-gnat-libs/buildlink3.mk"
.include "../../devel/gprbuild/buildlink3.mk"

GPRBUILD_OPTIONS+=	--config=../default.cgpr
GPRINSTALL_OPTIONS+=	--config=../default.cgpr

BUILDLINK_DEPMETHOD.xmlada=	full
.include "../../wip/xmlada/buildlink3.mk"

BUILDLINK_DEPMETHOD.gprlib=	full
.include "../../wip/gprlib/buildlink3.mk"

BUILDLINK_DEPMETHOD.gnatcoll-core=	full
.include "../../wip/gnatcoll-core/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
