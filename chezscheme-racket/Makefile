# $NetBSD$

DISTNAME=	racket-minimal-${DISTVERS}-src
DISTVERS=	8.5
PKGNAME=	chezscheme-racket-9.5.7.6
CATEGORIES=	lang
MASTER_SITES=	https://download.racket-lang.org/releases/${DISTVERS}/installers/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://download.racket-lang.org/installers/${DISTVERS}/
COMMENT=	Racket's fork of Chez Scheme
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/racket-${DISTVERS}
HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c

CONFLICTS=	chezscheme-[0-9]*

CONFIGURE_DIRS=	src/ChezScheme
BUILD_DIRS=	src/ChezScheme
BUILD_TARGET=	build

CHECK_PORTABILITY_SKIP=	src/cs/c/configure

.include "../../mk/bsd.prefs.mk"

# For now, we always build with threads support
CHEZ_THREADED=t

.if ${MACHINE_ARCH} == i386
CHEZ_ARCH=i3
.elif ${MACHINE_ARCH} == x86_64
CHEZ_ARCH=a6
.elif ${MACHINE_ARCH} == aarch64
CHEZ_ARCH=arm64
.endif

.if ${OPSYS} == NetBSD
CHEZ_OS=nb
.elif ${OPSYS} == FreeBSD
CHEZ_OS=fb
.elif ${OPSYS} == OpenBSD
CHEZ_OS=ob
.elif ${OPSYS} == Linux
CHEZ_OS=le
.elif ${OPSYS} == Darwin
CHEZ_OS=osx
.endif

PLIST_SUBST+=		CHEZ_THREADED=${CHEZ_THREADED}
PLIST_SUBST+=		CHEZ_ARCH=${CHEZ_ARCH}
PLIST_SUBST+=		CHEZ_OS=${CHEZ_OS}

post-extract:
	rm -rf ${WRKSRC}/src/bc ${WRKSRC}/src/cs

pre-configure:
	cd ${WRKSRC}/src/ChezScheme && \
		./configure --pb ZLIB=-lz \
		LZ4="`pkg-config --libs liblz4`" && \
		gmake ${CHEZ_THREADED}${CHEZ_ARCH}${CHEZ_OS}.bootquick

do-configure:
	cd ${WRKSRC}/src/ChezScheme && \
		./configure \
			ZLIB=-lz \
			LZ4="`pkg-config --libs liblz4`" \
			--threads \
			--disable-x11 \
			--installprefix=${PREFIX} \
			--installman=${PREFIX}/${PKGMANDIR} \
			--temproot=${DESTDIR}

post-install:
	mkdir -p ${DESTDIR}/${PREFIX}/share/examples/csv${PKGVERSION}
	${MV} -f \
		${DESTDIR}/${PREFIX}/lib/csv${PKGVERSION}/examples/*.c \
		${DESTDIR}/${PREFIX}/lib/csv${PKGVERSION}/examples/*.ss \
		${DESTDIR}/${PREFIX}/lib/csv${PKGVERSION}/examples/Makefile \
		${DESTDIR}/${PREFIX}/share/examples/csv${PKGVERSION}
	${RMDIR} ${DESTDIR}/${PREFIX}/lib/csv${PKGVERSION}/examples

.include "../../archivers/lz4/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
