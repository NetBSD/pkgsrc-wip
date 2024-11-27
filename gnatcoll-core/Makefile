# $NetBSD: Makefile,v 1.0 2024/05/06 15:00:00 dkazankov Exp $

PKGNAME=	gnatcoll-core-25.0.0
DISTNAME=	gnatcoll-core-${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	gnatcoll-core
GITHUB_TAG=	v${PKGVERSION_NOREV}

HOMEPAGE=	https://github.com/AdaCore/gnatcoll-core
COMMENT=	The GNAT Components Collection (GNATcoll) - Core packages
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=	c ada

MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} BUILD=PROD ENABLE_SHARED=yes

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} include lib share \( -type f -or -type l \) -print | ${SORT};

.include "../../wip/gcc14-gnat-libs/buildlink3.mk"

BUILDLINK_DEPMETHOD.xmlada=	full
.include "../../wip/xmlada/buildlink3.mk"

BUILDLINK_DEPMETHOD.gprlib=	full
.include "../../wip/gprlib/buildlink3.mk"

.include "../../wip/gprbuild/buildlink3.mk"

.include "../../wip/gcc14-gnat/gcc.mk"

PYTHON_VERSIONS_ACCEPTED=	312 311 310 39 38 27
.include "../../lang/python/tool.mk"

.include "../../mk/bsd.pkg.mk"
