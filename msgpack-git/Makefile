# $ NetBSD $

DISTNAME=	msgpack-2.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=msgpack/}
GITHUB_PROJECT=	msgpack-c
GITHUB_RELEASE=	cpp-${PKGVERSION_NOREV}
GITHUB_TYPE=	release

# GIT_REPOSITORIES=	msgpack
# GIT_REPO.msgpack=	git://github.com/msgpack/msgpack-c.git
# GIT_MODULE.msgpack=	msgpack-c
# WRKSRC=			${WRKDIR}/${GIT_MODULE.msgpack}

HOMEPAGE=	http://msgpack.org/
COMMENT=	Binary-based efficient object serialization library
LICENSE=	apache-2.0

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DMSGPACK_BUILD_TESTS=OFF
CMAKE_ARGS+=	-DMSGPACK_BUILD_EXAMPLES=OFF

CONFLICTS=	msgpack-[0-9]*

PKGCONFIG_OVERRIDE=	msgpack.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${_OPSYS_SHLIB_TYPE} == "dylib"
SOEXT=		dylib
.else
SOEXT=		so
.endif
PLIST_SUBST+=	SOEXT=${SOEXT}

.include "options.mk"

# .include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
