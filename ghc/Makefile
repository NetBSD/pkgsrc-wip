# $NetBSD: Makefile,v 1.12 2009/07/02 08:57:03 phonohawk Exp $

DISTNAME=		ghc-${VERSION}
VERSION=		6.10.3
CATEGORIES=		lang
MASTER_SITES=	http://www.haskell.org/ghc/dist/${VERSION}/
MAINTAINER=		kristerw@NetBSD.org
HOMEPAGE=		http://www.haskell.org/ghc/
COMMENT=		Compiler for the functional language Haskell
LICENSE=		modified-bsd

DISTFILES=		${DISTNAME}-src.tar.bz2 \
				ghc-6.6.1-src.tar.bz2 \
				ghc-6.6.1-i386-unknown-freebsd-hc.tar.gz \
				ghc-6.6.1-powerpc-apple-darwin-hc.tar.gz

SITES.ghc-6.6.1-src.tar.bz2						= http://www.haskell.org/ghc/dist/6.6.1/
SITES.ghc-6.6.1-powerpc-apple-darwin-hc.tar.gz	= http://static.cielonegro.org/archive/
SITES.ghc-6.6.1-i386-unknown-freebsd-hc.tar.gz	= http://static.cielonegro.org/archive/

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

# Unregisterised HC packages are architecture dependent. We have to
# create more HC packages to support more architectures.
ONLY_FOR_PLATFORM= *-*-i386 *-*-powerpc

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PerlCmd=${PERL5:Q}
USE_TOOLS+=			gmake perl:run find:run cp:run

# We don't want to extract all of the DISTFILEs.
EXTRACT_ONLY=	${DISTNAME}-src.tar.bz2 \
				ghc-6.6.1-src.tar.bz2

.if ${MACHINE_ARCH} == "i386"
EXTRACT_ONLY += ghc-6.6.1-i386-unknown-freebsd-hc.tar.gz
.elif ${MACHINE_ARCH} == "powerpc"
EXTRACT_ONLY += ghc-6.6.1-powerpc-apple-darwin-hc.tar.gz
.endif

# We need to tell the ./configure that libgmp is in a non-standard path. Without
# that, the resulting GHC tries to link programs by executing ld(1) without
# passing it -L${PREFIX}/lib.
CONFIGURE_ARGS += --with-gmp-includes=${PREFIX}/include
CONFIGURE_ARGS += --with-gmp-libraries=${PREFIX}/lib

# Build an unregisterised bootstrap compiler and install it directly
# into the .buildlink directory. But we can't use "make install"
# because we don't build it in a standard way (./configure && make).
#
# To install it, we search for any non-symlink executables in
# work/ghc-6.4.2 whose name ends with "-inplace". Then copy those
# files into ${BUILDLINK_DIR}/bin with dropping the "-inplace" at
# their tails.
pre-configure:
	cd ${WRKDIR}/ghc-6.6.1 && \
		${CHMOD} +x ./distrib/hc-build && \
		${ENV} ${CONFIGURE_ENV} ./distrib/hc-build -C --disable-readline --enable-hc-boot-unregisterised && \
		${FIND} . -type f -and -perm -o+x -and -name '*-inplace' | \
			while read i; do \
				${CP} $$i ${BUILDLINK_DIR}/bin/`basename $$i | sed -e 's/-inplace//'`; \
			done

# The ghc compiler does normally split the generated C files into small
# parts before sending them to gcc, to enable the linker to eliminate
# unused parts.  This does however not play nice with the pkgsrc
# framework, and the result is that the build takes more than 5 times
# as long than when the files are not split.  See
#    http://mail-index.netbsd.org/tech-pkg/2006/07/30/0005.html
# for a description of the problem.
# Disable file splitting until pkgsrc gets improved.
pre-build:
	${ECHO} "SplitObjs=NO" > ${WRKSRC}/mk/build.mk

# Some unused scripts don't pass the portability test.
CHECK_PORTABILITY_SKIP+=	distrib/prep-bin-dist-mingw

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
