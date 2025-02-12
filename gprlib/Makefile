# $NetBSD: Makefile,v 1.0 2024/05/06 15:00:00 dkazankov Exp $

PKGNAME=	gprlib-25.0.0
DISTNAME=	gprbuild-${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	gprbuild
GITHUB_TAG=	v${PKGVERSION_NOREV}

HOMEPAGE=	https://github.com/AdaCore/gprbuild
COMMENT=	LIBGPR development libraries
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
HAS_CONFIGURE=	yes

USE_LANGUAGES=	c ada

GCC_REQD+=	13

CONFIG_SHELL_FLAGS+=	prefix=${DESTDIR}${PREFIX} ENABLE_SHARED=yes
CONFIG_SHELL=		${MAKE_PROGRAM}
CONFIGURE_SCRIPT=	setup

BUILD_TARGET=		libgpr.build

INSTALL_TARGET=		libgpr.install

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} include lib share \( -type f -or -type l \) -print | ${SORT};

.include "../../mk/bsd.prefs.mk"

.include "../../lang/gcc13-gnat-libs/buildlink3.mk"
.include "../../wip/gprbuild/buildlink3.mk"

BUILDLINK_DEPMETHOD.xmlada=	full
.include "../../wip/xmlada/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
