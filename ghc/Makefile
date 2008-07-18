# $NetBSD: Makefile,v 1.5 2008/07/18 08:39:34 phonohawk Exp $

DISTNAME=	ghc-6.8.3
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://www.haskell.org/ghc/dist/6.8.3/
DISTFILES=	${DISTNAME}-src.tar.bz2 \
		${DISTNAME}-src-extralibs.tar.bz2 \
		ghc-6.4.2-src.tar.bz2 \
		ghc-6.4.2-i386-unknown-netbsd-hc.tar.gz

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin" && ${MACHINE_ARCH} == "powerpc"
DISTFILES+=	ghc-6.6-ppc-apple-darwin.tar.gz
.endif

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://www.haskell.org/ghc/
COMMENT=	Compiler for the functional language Haskell

SITES.ghc-6.4.2-src.tar.bz2=http://www.haskell.org/ghc/dist/6.4.2/
SITES.ghc-6.4.2-i386-unknown-netbsd-hc.tar.gz=${MASTER_SITE_LOCAL}
SITES.ghc-6.6-ppc-apple-darwin.tar.gz=http://haskell.org/ghc/dist/6.6/

ONLY_FOR_PLATFORM= Darwin-*-i386 FreeBSD-*-i386 NetBSD-*-i386 OpenBSD-*-i386 Darwin-*-powerpc

CHECK_PORTABILITY_SKIP=	distrib/prep-bin-dist-mingw

# += in a shell script, but in embedded AWK code, so it's ok.
CHECK_PORTABILITY_SKIP+=	libraries/base/cbits/ubconfc

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PerlCmd=${PERL5:Q}
USE_GNU_READLINE=	yes	# uses the UNDO_ constants
USE_TOOLS+=		gmake perl:run

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix+=	../ghc-6.4.2/mk/bootstrap.mk
SUBST_FILES.prefix+=	../ghc-6.4.2/ghc/rts/package.conf.in
SUBST_FILES.prefix+=	../ghc-6.4.2/libraries/readline/package.conf.in
SUBST_FILES.prefix+=	libraries/readline/configure
SUBST_FILES.prefix+=	libraries/readline/readline.cabal
SUBST_FILES.prefix+=	rts/package.conf.in
SUBST_SED.prefix=	-e 's,@PREFIX@,${PREFIX},g'

.if ${MACHINE_ARCH} == "i386"

CONFIGURE_ARGS+=	--with-ghc=${WRKDIR}/ghc-6.4.2/ghc/compiler/ghc-inplace

pre-configure:
	cd ${WRKDIR}/ghc-6.4.2 && \
		./distrib/hc-build --enable-hc-boot-unregisterised

.elif ${OPSYS} == "Darwin" && ${MACHINE_ARCH} == "powerpc"

# The binary distribution of GHC 6.6 for Darwin-*-powerpc has some
# prefix problems that prevent us from using it as an in-place
# compiler.
SUBST_CLASSES+=			inplace
SUBST_STAGE.inplace=	post-patch
SUBST_FILES.inplace+=	${WRKDIR}/ghc-6.6/bin/powerpc-apple-darwin/ghc-6.6.sh
SUBST_FILES.inplace+=	${WRKDIR}/ghc-6.6/bin/powerpc-apple-darwin/ghci-6.6.sh
SUBST_FILES.inplace+=	${WRKDIR}/ghc-6.6/bin/powerpc-apple-darwin/ghc-pkg-6.6.sh
SUBST_FILES.inplace+=	${WRKDIR}/ghc-6.6/lib/powerpc-apple-darwin/package.conf
SUBST_SED.inplace=		-e 's,/usr/local/lib/ghc-6.6,${WRKDIR}/ghc-6.6/lib/powerpc-apple-darwin,g'

# Some patches appends -R@PREFIX@/lib to ld-options, which isn't
# supported nor needed for Mach-O.
SUBST_CLASSES+=			rpath
SUBST_STAGE.rpath=		post-patch
SUBST_FILES.rpath+=		rts/package.conf.in
SUBST_FILES.rpath+=		libraries/readline/readline.cabal
SUBST_SED.rpath=		-e 's!"-Wl","-R${PREFIX}/lib",!!g'

CONFIGURE_ARGS+=	--with-ghc=${WRKDIR}/ghc-6.6/bin/powerpc-apple-darwin/ghc

pre-configure:
	cd ${WRKDIR}/ghc-6.6 && \
		./configure && \
		${MAKE_PROGRAM} in-place

.endif

# The ghc compiler does normally split the generated C files into small
# parts before sending them to gcc, to enable the linker to eliminate
# unused parts.  This does however not play nice with the pkgsrc
# framework, and the result is that the build takes more than 5 times
# as long than when the files are not split.  See
#    http://mail-index.netbsd.org/tech-pkg/2006/07/30/0005.html
# for a description of the problem.
# Disable file splitting until pkgsrc has been improved.
pre-build:
	${ECHO} "SplitObjs=NO" > ${WRKSRC}/mk/build.mk

.include "../../audio/openal/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
