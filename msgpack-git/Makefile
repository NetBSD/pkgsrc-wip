# $ NetBSD $

DISTNAME=	msgpack-1.0.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/msgpack/msgpack-c/releases/download/cpp-${PKGVERSION_NOREV}/

GIT_REPOSITORIES=	msgpack
GIT_REPO.msgpack=	git://github.com/msgpack/msgpack-c.git
GIT_MODULE.msgpack=	msgpack-c
WRKSRC=			${WRKDIR}/${GIT_MODULE.msgpack}

HOMEPAGE=	http://msgpack.org/
COMMENT=	Binary-based efficient object serialization library
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS=	aclocal autoconf automake autoheader

CONFLICTS=	msgpack-[0-9]*

PKGCONFIG_OVERRIDE=	msgpack.pc.in

GCC_REQD+=	4.1

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
CFLAGS+=	-march=i686
CXXFLAGS+=	-march=i686
.endif

pre-configure:
	cd ${WRKSRC} && ./bootstrap

.include "options.mk"

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
