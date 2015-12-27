# $NetBSD: Makefile,v 1.8 2013/06/20 21:36:28 morr Exp $

DISTNAME=	haproxy-1.5.15
CATEGORIES=	net www
MASTER_SITES=	http://www.haproxy.org/download/1.5/src/

MAINTAINER=	morr@NetBSD.org
HOMEPAGE=	http://haproxy.1wt.eu/
COMMENT=	Reliable, high performance TCP/HTTP load balancer
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake
BUILD_MAKE_FLAGS+=	TARGET=${TARGET} ADDLIB=${COMPILER_RPATH_FLAG}${PREFIX}/lib
BUILD_MAKE_FLAGS+=	USE_LIBCRYPT=1
#BUILD_MAKE_FLAGS+=	USE_CRYPT_H=1
BUILD_MAKE_FLAGS+=	USE_OPENSSL=1
BUILD_MAKE_FLAGS+=	USE_PCRE=1
BUILD_MAKE_FLAGS+=	USE_PCRE_JIT=1
#BUILD_MAKE_FLAGS+=	USE_STATIC_PCRE=1
BUILD_MAKE_FLAGS+=	USE_ZLIB=1
#.if ${MACHINE_ARCH} == "i386"
#BUILD_MAKE_FLAGS+=	CPU=i686
#.endif
INSTALL_MAKE_FLAGS+=	TARGET=${TARGET}
INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX}
INSTALL_MAKE_FLAGS+=	DOCDIR=${PREFIX}/share/doc/${PKGBASE}
INSTALL_MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
INSTALLATION_DIRS=	${EGDIR} share/examples/rc.d

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		rcd
.if ${OPSYS} == "NetBSD"
RCD_SCRIPTS=		haproxy
INSTALLATION_DIRS+=	share/examples/rc.d
PLIST.rcd=		yes
.endif

.if ${OPSYS} == "NetBSD"
TARGET=netbsd
.elif ${OPSYS} == "FreeBSD"
TARGET=freebsd
.elif ${OPSYS} == "OpenBSD"
TARGET=openbsd
.elif ${OPSYS} == "SunOS"
TARGET=solaris
.elif ${OPSYS} == "Linux"
.  if !empty(OS_VERSION:M2.6.*)
TARGET=linux26
.  elif !empty(OS_VERSION:M2.4.*)
.    if exists(/usr/include/linux/eventpoll.h)
TARGET=linux24e
.    else
TARGET=linux24
.    endif
.  endif
.else
TARGET=generic
.endif

LIBS.SunOS+=		-lxnet

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/haproxy.cfg ${DESTDIR}${EGDIR}/

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
