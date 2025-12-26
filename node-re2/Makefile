# $NetBSD$

DISTNAME=	node-re2-1.23.0
CATEGORIES=	devel textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=uhop/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/uhop/node-re2/
COMMENT=	node.js bindings for RE2
LICENSE=	modified-bsd

TOOL_DEPENDS+=	node-gyp-[0-9]*:../../wip/node-gyp

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

#LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib -L${PREFIX}/lib

#GITHUB_SUBMODULES+=	abseil abseil-cpp d38452e1ee03523a208362186fd42248ff2609f6 vendor/abseil-cpp
#GITHUB_SUBMODULES+=	google re2 927f5d53caf8111721e734cf24724686bb745f55 vendor/re2

pre-configure:
	 ${MV} ${BUILDLINK_DIR}/include/node/* ${BUILDLINK_DIR}/include

.include "../../wip/prettier/npm.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/nodejs/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
