# $NetBSD$

DISTNAME=	bigloo-4.5b
CATEGORIES=	lang
MASTER_SITES=	https://www-sop.inria.fr/indes/fp/Bigloo/download/

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://www-sop.inria.fr/indes/fp/Bigloo/
COMMENT=	Scheme development environment
LICENSE=	gnu-gpl-v2

CHECK_PORTABILITY_SKIP+=	api-contribs/bigloo-with-dbus/configure

USE_LANGUAGES=	c c++
USE_TOOLS=	gmake autoconf automake pkg-config
HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes
INFO_FILES=	yes

LDFLAGS+=	${COMPILER_RPATH_FLAG}

CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--cflags=${CFLAGS:M*:Q}
CONFIGURE_ARGS+=	--cpicflags="-fPIC"
CONFIGURE_ARGS+=	--ldflags=${LDFLAGS:M*:Q}
CONFIGURE_ARGS+=	--customgc=no
CONFIGURE_ARGS+=	--gccustominstall=skip
CONFIGURE_ARGS+=	--gclibdir=${PREFIX}/lib
CONFIGURE_ARGS+=	--gcincdir=${PREFIX}/include
CONFIGURE_ARGS+=	--customlibuv=no
CONFIGURE_ARGS+=	--disable-pcre
CONFIGURE_ARGS+=	--disable-pcre2
CONFIGURE_ARGS+=	--customunistring=no
CONFIGURE_ARGS+=	--disable-libbacktrace
CONFIGURE_ARGS+=	--native=yes
CONFIGURE_ARGS+=	--sharedcompiler=yes
CONFIGURE_ARGS+=	--sharedbde=yes
CONFIGURE_ARGS+=	--strip=no

BUILD_TARGET=	#empty

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=     opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
