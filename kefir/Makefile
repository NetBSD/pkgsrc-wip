# $NetBSD$

DISTNAME=	kefir-0.5.0
CATEGORIES=	devel
MASTER_SITES=	https://kefir.protopopov.lv/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kefir.protopopov.lv/
COMMENT=	C17/C23 compiler
LICENSE=	gnu-gpl-v3 AND modified-bsd

ONLY_FOR_PLATFORM=	*-*-x86_64

# uses grealpath during installation
TOOL_DEPENDS+=	coreutils-[0-9]*:../../sysutils/coreutils

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

PKGSRC_USE_FORTIFY=	no

MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	EXTRA_LDFLAGS=${COMPILER_RPATH_FLAG}${PREFIX}/lib

REPLACE_SH+=	scripts/kefir.m4
REPLACE_SH+=	scripts/detect-host-env.sh

.include "../../mk/bsd.pkg.mk"
