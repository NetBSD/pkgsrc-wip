# $NetBSD: Makefile,v 1.0 2024/05/13 13:00:00 dkazankov Exp $

DISTNAME=	gnatcoll-db-${PKGVERSION_NOREV}
PKGNAME=	gnatcoll-db-25.0.0
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	gnatcoll-db
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/gnatcoll-db
COMMENT=	The GNAT Components Collection (GNATcoll) - Database packages
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake grep

CHECK_PIE_SKIP+=	bin/*

USE_LANGUAGES=	c ada
# See xmlada package for rationale
GCC_REQD+=	13

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

SUBST_CLASSES+=		fixver
SUBST_STAGE.fixver=	pre-configure
SUBST_FILES.fixver=	version_information
SUBST_SED.fixver=	-e 's,0.0,25.0,g'
SUBST_MESSAGE.fixver=	Fix version information

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} bin include lib share \( -type f -or -type l \) -print | ${SORT};

CONFIGURE_ARGS+=	prefix=${DESTDIR}${PREFIX} BUILD=PROD BUILD_DIRS=${PKG_BUILD_DIRS:Q} \
	DB_BACKENDS=${DB_BACKENDS:Q}
MAKE_FLAGS+=		BUILD_DIRS=${PKG_BUILD_DIRS:Q} DB_BACKENDS=${DB_BACKENDS:Q}

do-configure:
	${RUN}${_ULIMIT_CMD} \
	cd ${WRKSRC} && \
	${PKGSRC_SETENV} ${CONFIGURE_ENV} \
	${MAKE_PROGRAM} ${CONFIGURE_ARGS} setup

.include "../../devel/gprbuild/buildlink3.mk"
.include "../../wip/xmlada/buildlink3.mk"
.include "../../wip/gprlib/buildlink3.mk"
.include "../../wip/gnatcoll-core/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
