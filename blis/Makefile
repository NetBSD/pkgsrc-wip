# $NetBSD$
#
BLIS_VERSION=	1.1
DISTNAME=	blis-${BLIS_VERSION}
PKGNAME=	blis-${BLIS_VERSION}
GITHUB_TAG=	${BLIS_VERSION}
MASTER_SITES=	${MASTER_SITE_GITHUB:=flame/}
MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/flame/libflame
LICENSE=	modified-bsd
COMMENT=	Framework for instantiating BLAS libraries
WRKSRC=		${WRKDIR}/blis-${GITHUB_TAG}


CATEGORIES=	math

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++ fortran
USE_TOOLS=	perl
USE_TOOLS+=	bash
USE_TOOLS+=	gmake

CONFIG_SHELL=		bash
CONFIGURE_ARGS+=	--prefix=${PREFIX}
#CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/lib
CONFIGURE_ARGS+=	--enable-blas
CONFIGURE_ARGS+=	--enable-cblas
CONFIGURE_ARGS+=	--enable-verbose-make


MAKE_ENV=	V=1
.include "../../wip/blis/options.mk"

# needs to be the last commandline argument
CONFIGURE_ARGS+=	auto

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} gmake test

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
