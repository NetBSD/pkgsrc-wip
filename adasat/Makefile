# $NetBSD: Makefile,v 1.0 2024/05/06 15:00:00 dkazankov Exp $

DISTNAME=	AdaSAT-${PKGVERSION_NOREV}
PKGNAME=	adasat-25.0.0
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	AdaSAT
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/AdaSAT
COMMENT=	Implementation of a DPLL-based SAT solver in Ada
LICENSE=	apache-2.0

USE_TOOLS+=	gmake

USE_LANGUAGES=	ada
# See xmlada package for rationale
GCC_REQD+=	13

USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"

USE_PKGSRC_GCC_RUNTIME?=	no

.if ${USE_PKGSRC_GCC_RUNTIME:tl} == "yes"
ALL_LIBRARY_TYPES=	static static-pic relocatable
.else
ALL_LIBRARY_TYPES=	static static-pic
.endif

MAKE_FLAGS+=	BUILD_MODE=prod
MAKE_FLAGS+=	ALL_LIBRARY_TYPES=${ALL_LIBRARY_TYPES:Q}
BUILD_TARGET=	all-libs

INSTALL_MAKE_FLAGS+=	INSTALL_DIR=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	ALL_LIBRARY_TYPES=${ALL_LIBRARY_TYPES:Q}

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} include lib share \( -type f -or -type l \) -print | ${SORT};

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
