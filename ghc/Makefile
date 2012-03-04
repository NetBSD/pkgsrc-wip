# $NetBSD: Makefile,v 1.31 2012/03/04 04:37:12 phonohawk Exp $

DISTNAME=	ghc-${VERSION}
VERSION=	7.4.1
CATEGORIES=	lang
MASTER_SITES=	http://www.haskell.org/ghc/dist/${VERSION}/
MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://www.haskell.org/ghc/
COMMENT=	Compiler for the functional language Haskell
LICENSE=	modified-bsd

DISTFILES=	${DISTNAME}-src.tar.bz2
DISTFILES+=	${DISTNAME}-boot-i386-unknown-freebsd8.0.tar.bz2
DISTFILES+=	${DISTNAME}-boot-i386-unknown-netbsdelf6.99.1.tar.bz2
DISTFILES+=	${DISTNAME}-boot-powerpc-apple-darwin9.8.0.tar.bz2

.for i in ${DISTFILES:M*-boot-*}
SITES.${i}=	http://static.cielonegro.org/archive/
.endfor

PKG_DESTDIR_SUPPORT=	user-destdir

# Unregisterised HC packages are platform-dependent C sources. Yes,
# they are C sources but are totally non-portable. We have to create
# more HC packages to support more platforms. Note that those packages
# are built with integer-simple, not integer-gmp, to reduce some
# complexity by not depending on the GMP. The resulting registerised
# GHC uses integer-gmp so this won't be a problem.
#
# If you want to build HC packages yourself, follow instructions in
# the ./TODO file.
ONLY_FOR_PLATFORM= NetBSD-*-i386 FreeBSD-*-i386 Darwin-*-powerpc

# We must provide the real path to gcc to the ./configure script,
# because GHC has a runtime dependency on it. Aren't there any ways
# better than this?
.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"
.if empty(CCPATH)
WARNINGS+= "This package depends on pkgsrc's undocumented variable \
CCPATH but it disappeared somehow."
WARNINGS+= "Using hard-coded /usr/bin/gcc as the C compiler..."
CONFIGURE_ARGS+= --with-gcc=/usr/bin/gcc
.else
CONFIGURE_ARGS+= --with-gcc=${CCPATH}
.endif

USE_TOOLS+=	autoconf date gmake gtar perl perl:run
CONFIGURE_ENV+=	PerlCmd=${PERL5:Q}

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

# Define ${PLATFORM} and the target "pre-configure".
.include "../../wip/ghc/stage0.mk"

do-configure:
	${RUN} cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS}
# We need to tell the libraries/terminfo/configure that our ncurses is
# in a non-standard path. Without that, the resulting GHC tries to
# link programs by executing ld(1) without passing it -L${PREFIX}/lib.
	${RUN} ${ECHO} "libraries/terminfo_CONFIGURE_OPTS += \
		--configure-option=--with-curses-includes=${PREFIX}/include \
		--configure-option=--with-curses-libraries=${PREFIX}/lib" >> ${WRKSRC}/mk/build.mk
# The ghc compiler does normally split the generated asm files into small
# parts before sending them to gcc, to enable the linker to eliminate
# unused parts.  This does however not play nice with the pkgsrc
# framework, and the result is that the build takes more than 5 times
# as long than when the files are not split.  See
#    http://mail-index.netbsd.org/tech-pkg/2006/07/30/0005.html
# for a description of the problem.
# Disable file splitting until pkgsrc gets improved.
	${RUN} ${ECHO} "SplitObjs = NO" >> ${WRKSRC}/mk/build.mk
# If we don't explicitly disable HsColour, PLIST gets changed
# depending on whether we have installed it or not.
	${RUN} ${ECHO} "HSCOLOUR_SRCS = NO" >> ${WRKSRC}/mk/build.mk

# Substitutions for INSTALL and DEINSTALL.
FILES_SUBST+=	DISTNAME=${DISTNAME}

# There is an unused script which don't pass the portability test.
CHECK_PORTABILITY_SKIP+=	distrib/prep-bin-dist-mingw

# GHC currently *requires* ${PREFIX}/lib to be in
# "/etc/ld-elf.so.conf". See
# http://hackage.haskell.org/trac/ghc/ticket/2933
CHECK_SHLIBS_SUPPORTED= 	no

# I guess pdcurses works well but not tested.
USE_NCURSES=	yes
.include "../../devel/ncurses/buildlink3.mk"

BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
BUILDLINK_DEPMETHOD.libxslt = build
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
