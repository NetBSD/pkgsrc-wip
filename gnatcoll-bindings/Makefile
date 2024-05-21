# $NetBSD: Makefile,v 1.0 2024/05/13 13:00:00 dkazankov Exp $

GNATCOLL_VERSION=	24.0.0

PKGNAME=	gnatcoll-bindings-${GNATCOLL_VERSION}
DISTNAME=	gnatcoll-bindings-${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	gnatcoll-bindings
GITHUB_TAG=	v${PKGVERSION_NOREV}

HOMEPAGE=	https://github.com/AdaCore/gnatcoll-bindings
COMMENT=	The GNAT Components Collection (GNATcoll) - Bindings
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=	c ada
GCC_REQD+=	13

.include "options.mk"

MAKE_FLAGS+=	BINDINGS=${BINDINGS:Q}
MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} BUILD=PROD ENABLE_SHARED=no

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} include lib share \( -type f -or -type l \) -print | ${SORT};

.include "../../wip/gprbuild/buildlink3.mk"
.include "../../wip/xmlada/buildlink3.mk"
.include "../../wip/gprlib/buildlink3.mk"
.include "../../wip/gnatcoll-core/buildlink3.mk"

PYTHON_VERSIONS_ACCEPTED=	312 311 310 39 38 27
.include "../../lang/python/tool.mk"

.include "../../mk/bsd.pkg.mk"
