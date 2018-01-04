# $NetBSD$

GITHUB_PROJECT=	ChezScheme
VERSION=	9.5
PKGNAME=	${GITHUB_PROJECT:tl}-${VERSION}
DISTNAME=	v${VERSION}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=cisco/}
GITHUB_TAG=     ${DISTNAME}
DIST_SUBDIR=	${GITHUB_PROJECT}
DISTFILES=	ChezScheme-${VERSION}.tar.gz \
		zlib-1.2.11.tar.gz \
		nanopass-framework-scheme-1.9.tar.gz \
		stex-1.2.1.tar.gz
SITES.zlib-1.2.11.tar.gz= -https://github.com/madler/zlib/archive/v1.2.11.tar.gz
SITES.ChezScheme-${VERSION}.tar.gz= -https://github.com/cisco/ChezScheme/archive/v${VERSION}.tar.gz
SITES.nanopass-framework-scheme-1.9.tar.gz= -https://github.com/nanopass/nanopass-framework-scheme/archive/v1.9.tar.gz
SITES.stex-1.2.1.tar.gz= -https://github.com/dybvig/stex/archive/v1.2.1.tar.gz

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
	cd ${WRKSRC} && rmdir stex && mv ../stex-1.2.1 stex && \
		        rmdir zlib && mv ../zlib-1.2.11 zlib &&  \
			rmdir nanopass && mv ../nanopass-framework-scheme-1.9 nanopass
do-configure:
	cd ${WRKSRC} && ./configure ${CONFIGURE_ARGS} \
                                    --installprefix=${PREFIX} \
                                    --installman=${PREFIX}/${PKGMANDIR} \
                                    --temproot=${DESTDIR} \
                                    LDFLAGS="${LDFLAGS}"

ONLY_FOR_PLATFORM+=	Linux-*-x86_64 Darwin-*-x86_64
ONLY_FOR_PLATFORM+=	Linux-*-i386 Darwin-*-i386
.if ${OPSYS} == Linux
PLIST_SUBST+=	OS=le
.elif ${OPSYS} == Darwin
PLIST_SUBST+=	OS=osx
.endif

.if ${MACHINE_ARCH} == i386
PLIST_SUBST+=	M=i3
.elif ${MACHINE_ARCH} == x86_64
PLIST_SUBST+=	M=a6
.endif

BUILD_TARGET=	build
PLIST_SUBST+=   T=${THR}

.include "../../mk/curses.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
