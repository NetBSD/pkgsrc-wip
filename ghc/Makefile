# $NetBSD: Makefile,v 1.35 2013/02/23 12:24:06 phonohawk Exp $
# -----------------------------------------------------------------------------
# Package metadata
#
DISTNAME=	ghc-${VERSION}
VERSION=	7.6.2
CATEGORIES=	lang
MASTER_SITES=	http://www.haskell.org/ghc/dist/${VERSION}/
MAINTAINER=	pho@cielonero.org
HOMEPAGE=	http://www.haskell.org/ghc/
COMMENT=	Compiler for the functional language Haskell
LICENSE=	modified-bsd

# GHC requires GHC to build itself. Formerly we could work around this
# bootstrapping problem by creating a special archive containing C
# sources compiled from Haskell sources, but that's no longer
# possible. So we have to prepare stripped-down binaries sufficient to
# bootstrap compilers for each platforms. If you want to build them
# yourself, follow an instruction in the ./TODO file.
ONLY_FOR_PLATFORM= \
	Darwin-*-powerpc \
	FreeBSD-*-i386 \
	Linux-*-x86_64 \
	NetBSD-*-i386 \
	NetBSD-*-x86_64


# -----------------------------------------------------------------------------
# Distfiles
#
DISTFILES=	${DISTNAME}-src.tar.bz2
DISTFILES+=	${DISTNAME}-boot-i386-unknown-freebsd.tar.xz
DISTFILES+=	${DISTNAME}-boot-i386-unknown-netbsd.tar.xz
DISTFILES+=	${DISTNAME}-boot-powerpc-apple-darwin.tar.xz
DISTFILES+=	${DISTNAME}-boot-x86_64-unknown-linux.tar.xz
DISTFILES+=	${DISTNAME}-boot-x86_64-unknown-netbsd.tar.xz

.for i in ${DISTFILES:M*-boot-*}
SITES.${i}=	http://static.cielonegro.org/archive/
.endfor

# We don't want to extract all of the DISTFILEs.
EXTRACT_ONLY=	${DISTNAME}-src.tar.bz2


# -----------------------------------------------------------------------------
# Tools
#
USE_TOOLS+=			autoconf gmake perl:run
GNU_CONFIGURE=			yes
USE_GNU_CONFIGURE_HOST=	no

# We must provide the real path to gcc to the ./configure script,
# because GHC has a runtime dependency on it. Aren't there any ways
# better than this?
.include "../../mk/compiler.mk"
.if empty(CCPATH)
CCPATH=	/usr/bin/gcc
WARNINGS+="This package depends on pkgsrc's undocumented variable\
CCPATH but it disappeared somehow."
WARNINGS+="Using hard-coded ${CCPATH:Q} as the C compiler..."
.endif

CONFIGURE_ARGS+= \
	--with-gcc=${CCPATH:Q} \
	--with-gmp-includes=${PREFIX:Q}/include \
	--with-gmp-libraries=${PREFIX:Q}/lib \
	--with-iconv-includes=${PREFIX:Q}/include \
	--with-iconv-libraries=${PREFIX:Q}/lib

CONFIGURE_ENV+= \
	PerlCmd=${PERL5:Q}


# -----------------------------------------------------------------------------
# Build hooks
#

# We patch configure.ac in some directories.
post-patch:
	@${PHASE_MSG} "Regenerating configuration scripts for ${PKGNAME}"
	${RUN} cd ${WRKSRC:Q}/libraries/integer-gmp && autoconf


# Define the target "pre-configure" and non-standard "bootstrap".
.include "../../wip/ghc/bootstrap.mk"


# Our pre-configure phase installs a bindist of bootstrapping compiler
# directly into TOOLS_DIR so that ./configure can find it.
do-configure:
	${RUN} cd ${WRKSRC:Q} && \
		${SETENV} ${CONFIGURE_ENV} ${SH} ./configure ${CONFIGURE_ARGS}

# Here we generate mk/build.mk dynamically.
	${RUN} ${RM} -f ${WRKSRC:Q}/mk/build.mk

# We need to tell the libraries/terminfo/configure that our ncurses is
# in a non-standard path. Without that, the resulting GHC tries to
# link programs by executing ld(1) without passing it -L${PREFIX:Q}/lib.
	${RUN} ${ECHO} "libraries/terminfo_CONFIGURE_OPTS += \
		--configure-option=--with-curses-includes=${PREFIX:Q}/include \
		--configure-option=--with-curses-libraries=${PREFIX:Q}/lib" >> ${WRKSRC:Q}/mk/build.mk

# The ghc compiler does normally split the generated asm files into small
# parts before sending them to gcc, to enable the linker to eliminate
# unused parts.  This does however not play nice with the pkgsrc
# framework, and the result is that the build takes more than 5 times
# as long than when the files are not split.  See
#    http://mail-index.netbsd.org/tech-pkg/2006/07/30/0005.html
# for a description of the problem.
# Disable file splitting until pkgsrc gets improved.
	${RUN} ${ECHO} "SplitObjs         = NO" >> ${WRKSRC:Q}/mk/build.mk

# If there is HsColour is in the PATH, GHC's build system tries to use
# it without even checking if it really works. That's not what we
# appreciate.
	${RUN} ${ECHO} "HSCOLOUR_SRCS     = NO" >> ${WRKSRC:Q}/mk/build.mk

# Don't even think of PDF.
	${RUN} ${ECHO} "BUILD_DOCBOOK_PS  = NO" >> ${WRKSRC:Q}/mk/build.mk
	${RUN} ${ECHO} "BUILD_DOCBOOK_PDF = NO" >> ${WRKSRC:Q}/mk/build.mk


# -----------------------------------------------------------------------------
# Installation/removal hooks
#

# Substitutions for INSTALL and DEINSTALL that handles package.cache.
FILES_SUBST+=	DISTNAME=${DISTNAME}

# We don't want package.cache to be in the PLIST.
post-install:
	${RM} -f ${DESTDIR:Q}${PREFIX:Q}/lib/${DISTNAME}/package.conf.d/package.cache


# -----------------------------------------------------------------------------
# PLIST
#
# We can't use static PLIST because the package installs some files
# whose names are randomly generated, namely
# lib/${PKGNAME}/package.conf.d/*.conf
#

# If we were lucky we could just use "PLIST_TYPE = dynamic", but the
# feature has seemingly bitrotted.
.include "../../mk/bsd.prefs.mk"
.if empty(DESTDIR)
PKG_FAIL_REASON+="This package can not be built without using DESTDIR.\
You need to set USE_DESTDIR to \"yes\"."
.else
GENERATE_PLIST+= \
	cd ${DESTDIR:Q}${PREFIX:Q} && \
		${FIND} * \( -type f -or -type l \) | ${SORT} -d;
.endif


# -----------------------------------------------------------------------------
# Sanity checks
#

# There is an unused script which don't pass the portability test.
CHECK_PORTABILITY_SKIP+=	distrib/prep-bin-dist-mingw

# GHC currently *requires* ${PREFIX}/lib to be in
# "/etc/ld-elf.so.conf". See
# http://hackage.haskell.org/trac/ghc/ticket/2933
CHECK_SHLIBS_SUPPORTED=	no


# -----------------------------------------------------------------------------
# Dependencies
#

# I guess pdcurses works well but not tested.
USE_NCURSES=	yes

BUILDLINK_DEPMETHOD.docbook-xsl=	build
BUILDLINK_DEPMETHOD.libxslt=		build
BUILDLINK_DEPMETHOD.xz=		build
.include "../../archivers/xz/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/docbook-xsl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
