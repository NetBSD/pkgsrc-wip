# $NetBSD: Makefile,v 1.0 2024/05/13 13:00:00 dkazankov Exp $

PKGNAME=	gnatcoll-bindings-25.0.0
DISTNAME=	gnatcoll-bindings-${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	gnatcoll-bindings
GITHUB_TAG=	v${PKGVERSION_NOREV}

HOMEPAGE=	https://github.com/AdaCore/gnatcoll-bindings
COMMENT=	The GNAT Components Collection (GNATcoll) - Bindings
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake grep

USE_LANGUAGES=	c cpp ada

GCC_REQD+=	13

SUBST_CLASSES+=		fixver
SUBST_STAGE.fixver=	pre-configure
SUBST_FILES.fixver=	version_information
SUBST_SED.fixver=	-e 's,0.0,25.0,g'
SUBST_MESSAGE.fixver=	Fix version information

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} include lib share \( -type f -or -type l \) -print | ${SORT};

.include "../../mk/bsd.prefs.mk"

.include "options.mk"

MAKE_FLAGS+=	BINDINGS=${BINDINGS:Q}
MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} BUILD=PROD ENABLE_SHARED=yes


.include "../../lang/gcc13-gnat-libs/buildlink3.mk"
.include "../../wip/gprbuild/buildlink3.mk"

BUILDLINK_DEPMETHOD.xmlada=	full
.include "../../wip/xmlada/buildlink3.mk"

BUILDLINK_DEPMETHOD.gprlib=	full
.include "../../wip/gprlib/buildlink3.mk"

BUILDLINK_DEPMETHOD.gnatcoll-core=	full
.include "../../wip/gnatcoll-core/buildlink3.mk"

PYTHON_VERSIONS_ACCEPTED=	312 311 310 39 38 27
.include "../../lang/python/tool.mk"

.include "../../mk/bsd.pkg.mk"
