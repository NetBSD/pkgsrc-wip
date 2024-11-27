# $NetBSD: Makefile,v 1.0 2024/05/06 15:00:00 dkazankov Exp $

PKGNAME=	adasat-25.0.0
CATEGORIES=	math
COMMENT=	Implementation of a DPLL-based SAT solver in Ada

DISTNAME=	AdaSAT-${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	AdaSAT

HOMEPAGE=	https://github.com/AdaCore/AdaSAT
LICENSE=	apache-2.0

USE_TOOLS+=	gmake

CHECK_RELRO_SUPPORTED=	no

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=	ada

MAKE_FLAGS=	BUILD_MODE=prod
BUILD_TARGET=	all-libs

INSTALL_MAKE_FLAGS=	INSTALL_DIR=${DESTDIR}${PREFIX}

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} include lib share \( -type f -or -type l \) -print | ${SORT};

.include "../../wip/gcc14-gnat-libs/buildlink3.mk"

.include "../../wip/gprbuild/buildlink3.mk"

.include "../../wip/gcc14-gnat/gcc.mk"

.include "../../mk/bsd.pkg.mk"
