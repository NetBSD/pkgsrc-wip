# $NetBSD: Makefile,v 1.0 2024/05/06 15:00:00 dkazankov Exp $

GNATCOLL_VERSION=	24.0.0

PKGNAME=	gnatcoll-core-${GNATCOLL_VERSION}
DISTNAME=	gnatcoll-core-${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	gnatcoll-core
GITHUB_TAG=	v${PKGVERSION_NOREV}

HOMEPAGE=	https://github.com/AdaCore/gnatcoll-core
COMMENT=	The GNAT Components Collection (GNATcoll) - Core packages
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
HAS_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=	c ada
GCC_REQD+=	13

CONFIG_SHELL_FLAGS+=	prefix=${DESTDIR}${PREFIX} BUILD=PROD ENABLE_SHARED=no
CONFIG_SHELL=		${MAKE_PROGRAM}
CONFIGURE_SCRIPT=	setup

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} include lib share \( -type f -or -type l \) -print | ${SORT};

.include "../../wip/gprbuild/buildlink3.mk"
.include "../../wip/xmlada/buildlink3.mk"
.include "../../wip/gprlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
