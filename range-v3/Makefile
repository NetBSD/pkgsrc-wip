# $NebBSD$

DISTNAME=           range-v3-0.10.0
CATEGORIES=         devel
MASTER_SITES=       ${MASTER_SITE_GITHUB:=ericniebler/}
GITHUB_TAG=         ${PKGVERSION_NOREV}

MAINTAINER=         jake.slazenger@yandex.com
HOMEPAGE=           https://github.com/ericniebler/range-v3
COMMENT=            Range library for C++14/17/20
LICENSE=            boost-license

ONLY_FOR_COMPILER=  gcc
USE_LANGUAGES=      c c++ gnu++14
USE_CMAKE=          yes

GCC_REQD=          6

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
