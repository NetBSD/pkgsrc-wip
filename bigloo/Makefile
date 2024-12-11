# $NetBSD$

DISTNAME=	bigloo-4.5b
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp-sop.inria.fr/indes/fp/Bigloo/

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	ftp://ftp-sop.inria.fr/indes/fp/Bigloo/
COMMENT=	Scheme development environment
LICENSE=	gnu-gpl-v2

CHECK_PORTABILITY_SKIP+=	api-contribs/bigloo-with-dbus/configure

USE_LANGUAGE=	c c++
USE_TOOLS=	gmake autoconf automake alocal pkg-config
HAS_CONFIGURE=		yes
GNU_CONFIGURE=	yes

LDFLAGS+=	-Wl,-rpath,${PREFIX}/lib

CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=/usr/pkg/man
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib
CONFIGURE_ARGS+=	--cflags=${CFLAGS:Q}
CONFIGURE_ARGS+=	--lflags=${LDFLAGS:Q}
CONFIGURE_ARGS+=	--customgc=no
CONFIGURE_ARGS+=	--gccustominstall=skip
CONFIGURE_ARGS+=	--gclibdir=${PREFIX}/lib
CONFIGURE_ARGS+=	--gcincdir=${PREFIX}/include
CONFIGURE_ARGS+=	--customlibuv=no
CONFIGURE_ARGS+=	--disable-pcre
CONFIGURE_ARGS+=	--disable-pcre2
CONFIGURE_ARGS+=	--customunistring=no
CONFIGURE_ARGS+=	--disable-libbacktrace

#do-configure:
#	cd ${WRKSRC} && ./configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ${MAKE_ENVS} LDFLAGS=${LDFLAGS:Q} CFLAGS=${CFLAGS:Q} ${GMAKE}


.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
#.include "../../wip/libbacktrace/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=     opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
