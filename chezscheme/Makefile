# $NetBSD$

GITHUB_PROJECT=	ChezScheme
VERSION=	9.5.8
PKGNAME=	${GITHUB_PROJECT:tl}-${VERSION}
DISTNAME=	v${VERSION}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=cisco/}
GITHUB_TAG=	${DISTNAME}
DIST_SUBDIR=	${GITHUB_PROJECT}
ZLIB_VERSION=	1.2.12
LZ4_VERSION=	1.9.2
NANOPASS_VERSION=1.9.2
STEX_VERSION=	1.2.2

DISTFILES=	ChezScheme-${VERSION}.tar.gz \
		zlib-${ZLIB_VERSION}.tar.gz \
		lz4-${LZ4_VERSION}.tar.gz \
		nanopass-framework-scheme-${NANOPASS_VERSION}.tar.gz \
		stex-${STEX_VERSION}.tar.gz
SITES.ChezScheme-${VERSION}.tar.gz= \
		-https://github.com/cisco/ChezScheme/archive/v${VERSION}.tar.gz
SITES.zlib-${ZLIB_VERSION}.tar.gz=	\
		-https://github.com/madler/zlib/archive/v${ZLIB_VERSION}.tar.gz
SITES.lz4-${LZ4_VERSION}.tar.gz= \
		-https://github.com/lz4/lz4/archive/v${LZ4_VERSION}.tar.gz
SITES.nanopass-framework-scheme-${NANOPASS_VERSION}.tar.gz= \
		-https://github.com/nanopass/nanopass-framework-scheme/archive/v${NANOPASS_VERSION}.tar.gz
SITES.stex-${STEX_VERSION}.tar.gz= \
		-https://github.com/dybvig/stex/archive/v${STEX_VERSION}.tar.gz

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://cisco.github.io/ChezScheme/
COMMENT=	Cisco implementation of the Scheme programming language
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/ChezScheme-${VERSION}
HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES+=	c

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && rmdir stex && mv ../stex-${STEX_VERSION} stex && \
		        rmdir zlib && mv ../zlib-${ZLIB_VERSION} zlib &&  \
		        rmdir lz4 && mv ../lz4-${LZ4_VERSION} lz4 &&  \
			rmdir nanopass && mv ../nanopass-framework-scheme-${NANOPASS_VERSION} nanopass
do-configure:
	cd ${WRKSRC} && ./configure ${CONFIGURE_ARGS} \
                                    --installprefix=${PREFIX} \
                                    --installman=${PREFIX}/${PKGMANDIR} \
                                    --temproot=${DESTDIR} \
                                    LDFLAGS="${LDFLAGS}"

ONLY_FOR_PLATFORM+=	Linux-*-x86_64 Darwin-*-x86_64
ONLY_FOR_PLATFORM+=	Linux-*-i386 Darwin-*-i386
.if ${OPSYS} == Linux
PLIST_SUBST+=		OS=le
.elif ${OPSYS} == Darwin
PLIST_SUBST+=		OS=osx
.endif

.if ${MACHINE_ARCH} == i386
PLIST_SUBST+=	M=i3
.elif ${MACHINE_ARCH} == x86_64
PLIST_SUBST+=	M=a6
.endif

BUILD_TARGET=	build
PLIST_SUBST+=	T=${THR}

.include "../../mk/curses.buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
