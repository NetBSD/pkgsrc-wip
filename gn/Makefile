# $NetBSD: Makefile,v 1.1 2025/08/31 12:03:34 ryoon Exp $

DISTNAME=	gn-20261110
CATEGORIES=	devel
MASTER_SITES=	https://gn.googlesource.com/gn.git/+archive/
GN_REVISION=	4df39f484f1f49f5c7f6264adc88d27811cb7b00
DIST_SUBDIR=	gn
DISTFILES=	${GN_REVISION}${EXTRACT_SUFX}

MAINTAINER=	kikadf@NetBSD.org
HOMEPAGE=	https://gn.googlesource.com/gn/
COMMENT=	Meta-build system that generates build files for Ninja
LICENSE=	modified-bsd

REPLACE_PYTHON=	build/gen.py

TOOL_DEPENDS+=	ninja-build-[0-9]*:../../devel/ninja-build

USE_LANGUAGES=	c c++

HAS_CONFIGURE=		yes
CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_SCRIPT=	build/gen.py
CONFIGURE_ARGS=		--no-last-commit-position
CONFIGURE_ARGS+=	--allow-warnings
CONFIGURE_ENV+=		GN_VERSION=${PKGVERSION_NOREV}
CONFIGURE_ENV+=		GN_REVISION=${GN_REVISION}

EXTRACT_DIR=		${WRKDIR}/${DISTNAME}
INSTALLATION_DIRS+=	bin

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ninja -j ${_MAKE_JOBS_N} -C out gn

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out/gn ${DESTDIR}${PREFIX}/bin


.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
