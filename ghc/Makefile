# $NetBSD: Makefile,v 1.20 2010/01/24 02:59:00 phonohawk Exp $

DISTNAME=		ghc-${VERSION}
VERSION=		6.12.1
CATEGORIES=		lang
MASTER_SITES=	http://www.haskell.org/ghc/dist/${VERSION}/
MAINTAINER=		kristerw@NetBSD.org
HOMEPAGE=		http://www.haskell.org/ghc/
COMMENT=		Compiler for the functional language Haskell
LICENSE=		modified-bsd

DISTFILES=		${DISTNAME}-src.tar.bz2 \
				${DISTNAME}-boot-i386-unknown-netbsd.tar.bz2 \
				${DISTNAME}-boot-i386-unknown-freebsd.tar.bz2 \
				${DISTNAME}-boot-powerpc-apple-darwin.tar.bz2

SITES.${DISTNAME}-src.tar.bz2						= http://www.haskell.org/ghc/dist/${VERSION}/
SITES.${DISTNAME}-boot-i386-unknown-netbsd.tar.bz2	= http://static.cielonegro.org/archive/
SITES.${DISTNAME}-boot-i386-unknown-freebsd.tar.bz2	= http://static.cielonegro.org/archive/
SITES.${DISTNAME}-boot-powerpc-apple-darwin.tar.bz2	= http://static.cielonegro.org/archive/

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

# Unregisterised HC packages are architecture dependent. We have to
# create more HC packages to support more architectures. Note that
# these packages are built with integer-simple, not integer-gmp, to
# reduce some complexity by not depending on the GMP. The resulting
# registerised GHC uses integer-gmp so this won't be a problem.
ONLY_FOR_PLATFORM= NetBSD-*-i386 FreeBSD-*-i386 Darwin-*-powerpc

# We must provide the real pass to gcc to the ./configure script,
# because GHC has a runtime dependency on it. Aren't there any better
# way than this?
.include "../../mk/compiler.mk"
.if empty(CCPATH)
WARNINGS+= "This package depends on pkgsrc's undocumented variable\
CCPATH but it disappeared somehow."
WARNINGS+= "Using hard-coded /usr/bin/gcc as the C compiler..."
CONFIGURE_ARGS+= --with-gcc=/usr/bin/gcc
.else
CONFIGURE_ARGS+= --with-gcc=${CCPATH}
.endif

USE_TOOLS+=	gmake bsdtar perl:run
CONFIGURE_ENV+=		PerlCmd=${PERL5:Q}

# We don't want to extract all of the DISTFILEs.
EXTRACT_ONLY=	${DISTNAME}-src.tar.bz2

CONFIGURE_ARGS += \
	--build=${PLATFORM} \
	--host=${PLATFORM} \
	--target=${PLATFORM} \
	--prefix=${PREFIX} \
	--mandir=${PREFIX}/${PKGMANDIR} \
	--with-gmp-includes=${PREFIX}/include \
	--with-gmp-libraries=${PREFIX}/lib \
	--with-iconv-includes=${PREFIX}/include \
	--with-iconv-libraries=${PREFIX}/lib

# Build an unregisterised bootstrap compiler and install it directly
# into the .buildlink directory. But we can't use "make install"
# because we don't build it in a standard way (./configure && make).
#
# To install it, we just copy ghc and ghc-pkg from
# "work/bootstrap/ghc-${VERSION}/inplace/bin" to
# "${BUILDLINK_DIR}/bin". Note that in-place ghc isn't usable before
# running "ghc-pkg recache".

.if ${MACHINE_ARCH} == "i386" && ${OPSYS} == "NetBSD"
BOOTSTRAP_BUILD_MK = ${PKGDIR}/files/bootstrap-bsd.mk
PLATFORM           = i386-unknown-netbsd

.elif ${MACHINE_ARCH} == "i386" && ${OPSYS} == "FreeBSD"
BOOTSTRAP_BUILD_MK = ${PKGDIR}/files/bootstrap-bsd.mk
PLATFORM           = i386-unknown-freebsd

.elif ${MACHINE_ARCH} == "powerpc" && ${OPSYS} == "Darwin"
BOOTSTRAP_BUILD_MK = ${PKGDIR}/files/bootstrap.mk
PLATFORM           = powerpc-apple-darwin

# Existence of libelf makes LeadingUnderscore being "NO", which is
# incorrect. See ghc-6.12.1/aclocal.m4 (FP_LEADING_UNDERSCORE)
CONFLICTS=	libelf-[0-9]*

.else
PKG_FAIL_REASON+=	"internal error: unsupported platform"
.endif

BOOTSTRAP_TARBALL = ${DISTNAME}-boot-${PLATFORM}.tar.bz2

pre-configure:
	${RUN} cd ${WRKDIR} && \
		${ECHO} "====> Preparing bootstrap compiler" && \
		${MKDIR} bootstrap && \
		${CP} -r ${DISTNAME} bootstrap && \
		cd bootstrap/${DISTNAME} && \
		${LN} -sf ${PWD_CMD} utils/ghc-pwd/ghc-pwd && \
		${ECHO} "====> Configuring for bootstrap compiler" && \
		${SETENV} ${CONFIGURE_ENV} ./configure --enable-hc-boot ${CONFIGURE_ARGS} && \
		${ECHO} "====> Extracting bootstrap HC archive" && \
		(cd .. && bsdtar jxfm ${DISTDIR}/${BOOTSTRAP_TARBALL}) && \
		${SH} mkfiles && \
		${ECHO} "====> Building bootstrap compiler" && \
		${SED} -e "s#\\[\\[PREFIX\\]\\]#${PREFIX}#g" ${BOOTSTRAP_BUILD_MK} > mk/build.mk && \
		for c in libraries/*/configure; do \
			(cd `${DIRNAME} $$c` && ${SETENV} ${CONFIGURE_ENV} ${SH} configure ${CONFIGURE_ARGS}); \
		done && \
		for i in inplace/lib/package.conf.d/*.conf */*/package-data.mk */*/*/package-data.mk; do \
			${SED} -e "s#\\[\\[GHC_SOURCE_PATH\\]\\]#`${PWD_CMD}`#g" $$i > $$i.tmp; \
			${MV} -f $$i.tmp $$i; \
		done && \
		${TOUCH} -r inplace/lib/package.conf.d */*/package-data.mk */*/*/package-data.mk && \
		${GMAKE} bootstrapping-files && \
		${GMAKE} all_ghc_stage2 && \
		${GMAKE} inplace/bin/ghc-pkg && \
		${GMAKE} inplace/lib/unlit && \
		inplace/bin/ghc-pkg recache && \
		${CP} inplace/bin/ghc-stage2 ${BUILDLINK_DIR}/bin/ghc && \
		${CP} inplace/bin/ghc-pkg ${BUILDLINK_DIR}/bin/ghc-pkg

# We need to tell the libraries/integer-gmp/configure that libgmp is
# in a non-standard path. Without that, the resulting GHC tries to
# link programs by executing ld(1) without passing it -L${PREFIX}/lib.
do-configure:
	${RUN} cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS}
	${RUN} ${ECHO} "libraries/integer-gmp_CONFIGURE_OPTS += \
		--configure-option=--with-gmp-includes=${PREFIX}/include \
		--configure-option=--with-gmp-libraries=${PREFIX}/lib" > ${WRKSRC}/mk/build.mk
	${RUN} ${ECHO} "libraries/terminfo_CONFIGURE_OPTS += \
		--configure-option=--with-curses-includes=${PREFIX}/include \
		--configure-option=--with-curses-libraries=${PREFIX}/lib" >> ${WRKSRC}/mk/build.mk

# The ghc compiler does normally split the generated C files into small
# parts before sending them to gcc, to enable the linker to eliminate
# unused parts.  This does however not play nice with the pkgsrc
# framework, and the result is that the build takes more than 5 times
# as long than when the files are not split.  See
#    http://mail-index.netbsd.org/tech-pkg/2006/07/30/0005.html
# for a description of the problem.
# Disable file splitting until pkgsrc gets improved.
pre-build:
	${RUN} ${ECHO} "SplitObjs = NO" >> ${WRKSRC}/mk/build.mk
# We have to sacrifice the GHCi library for GHC itself to work around
# for powerpc ld bug.  See
# http://hackage.haskell.org/trac/ghc/ticket/3260
.if ${MACHINE_ARCH} == "powerpc"
	${RUN} ${MKDIR} ${WRKSRC}/compiler/stage1/build
	${RUN} ${TOUCH} -t `expr \`date '+%Y'\` + 1`12310000 \
					${WRKSRC}/compiler/stage1/build/HS${DISTNAME}.o
	${RUN} ${MKDIR} ${WRKSRC}/compiler/stage2/build
	${RUN} ${TOUCH} -t `expr \`date '+%Y'\` + 1`12310000 \
					${WRKSRC}/compiler/stage2/build/HS${DISTNAME}.o
.endif

.if ${MACHINE_ARCH} == "powerpc"
WARNINGS+= "You won't be able to use GHCi library for GHC itself\
because of powerpc ld bug."
.endif

# Some unused scripts don't pass the portability test.
CHECK_PORTABILITY_SKIP+=	distrib/prep-bin-dist-mingw

# GHC currently *requires* ${PREFIX}/lib to be in
# "/etc/ld-elf.so.conf". See
# http://hackage.haskell.org/trac/ghc/ticket/2933
CHECK_SHLIBS_SUPPORTED= 	no

BUILDLINK_DEPMETHOD.libxslt = build
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
