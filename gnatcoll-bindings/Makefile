# $NetBSD: Makefile,v 1.0 2024/05/13 13:00:00 dkazankov Exp $

DISTNAME=	gnatcoll-bindings-${PKGVERSION_NOREV}
PKGNAME=	gnatcoll-bindings-25.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	gnatcoll-bindings
GITHUB_TAG=	v${PKGVERSION_NOREV}

HOMEPAGE=	https://github.com/AdaCore/gnatcoll-bindings
COMMENT=	The GNAT Components Collection (GNATcoll) - Bindings
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake grep

USE_LANGUAGES=	c c++ ada

GCC_REQD+=	13

USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"

.include "options.mk"

SUBST_CLASSES+=		fixver
SUBST_STAGE.fixver=	pre-configure
SUBST_FILES.fixver=	version_information
SUBST_SED.fixver=	-e 's,0.0,25.0,g'
SUBST_MESSAGE.fixver=	Fix version information

MAKE_FLAGS+=	BINDINGS=${BINDINGS:Q}
MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} BUILD=PROD

USE_PKGSRC_GCC_RUNTIME?=		no
.if ${USE_PKGSRC_GCC_RUNTIME:tl} == "yes"
MAKE_FLAGS+=				ENABLE_SHARED=yes
BUILDLINK_DEPMETHOD.xmlada=		full
BUILDLINK_DEPMETHOD.gprlib=		full
BUILDLINK_DEPMETHOD.gnatcoll-core=	full
.else
MAKE_FLAGS+=				ENABLE_SHARED=no
.endif

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} include lib share \( -type f -or -type l \) -print | ${SORT};

.include "../../devel/gprbuild/buildlink3.mk"
.include "../../wip/xmlada/buildlink3.mk"
.include "../../wip/gprlib/buildlink3.mk"
.include "../../wip/gnatcoll-core/buildlink3.mk"

.include "../../lang/python/tool.mk"

.include "../../mk/bsd.pkg.mk"
