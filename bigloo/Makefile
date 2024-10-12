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

# TODO: do this better
C_ARGS=	--prefix=${PREFIX} --mandir=/usr/pkg/man
C_ARGS+=	--customgc=no
C_ARGS+=	--gccustominstall=skip
C_ARGS+=	--gclibdir=${PREFIX}/lib
C_ARGS+=	--gcincdir=${PREFIX}/include
C_ARGS+=	--customlibuv=no
C_ARGS+=	--disable-pcre
C_ARGS+=	--disable-pcre2
C_ARGS+=	--customunistring=no
C_ARGS+=	--disable-libbacktrace

do-configure:
	cd ${WRKSRC} && ./configure ${C_ARGS}

#TODO: do this better as well
do-build:
	cd ${WRKSRC} && ${MAKE_ENVS} LDFLAGS="${LDFLAGS}" CFLAGS="${CFLAGS}" ${GMAKE}


.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
#.include "../../wip/libbacktrace/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=     opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
