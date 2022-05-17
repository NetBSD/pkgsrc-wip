# $NetBSD$

DISTNAME=	1.1.0
PKGNAME=	fennel-1.1.0
CATEGORIES=	lang
MASTER_SITES=	https://git.sr.ht/~technomancy/fennel/archive/

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://fennel-lang.org/
COMMENT=	The Fennel programming language
LICENSE=	mit

USE_LANGUAGES=	c
USE_TOOLS+=	gmake
NO_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PKGNAME}

BUILD_TARGET=	build

# We can't use lang/lua/application.mk's 'REPLACE_LUA' facility because that
# is evaluated at configure-time -- which won't work because the shebang
# statement we're trying to fix is written to our script afterwards, at
# *build* time.
#
# Therefore, use this modification we've made to the Makefile, where we pass
# in the LUA_INTERPRETER directly.
MAKE_FLAGS+=	LUA_INTERPRETER=${LUA_INTERPRETER}

INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX}
INSTALL_MAKE_FLAGS+=	MAN_DIR=${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/lua/application.mk"
.include "../../mk/bsd.pkg.mk"
