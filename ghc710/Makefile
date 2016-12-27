# $NetBSD$

DISTNAME=	ghc-7.10.3-src
PKGNAME=	ghc710-7.10.3
CATEGORIES=	lang
MASTER_SITES=	http://www.haskell.org/ghc/dist/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz
DISTFILES=	ghc-7.10.3-src.tar.xz
DISTFILES+=	ghc-7.10.3-testsuite.tar.xz


MAINTAINER=			sandro.r.millien@gmail.com
HOMEPAGE=			http://www.haskell.org/ghc/
COMMENT=			Compiler for the functional language Haskell
LICENSE=			modified-bsd



WRKSRC=				${WRKDIR}/ghc-7.10.3

GHC_SUBPREFIX=		ghc710

GNU_CONFIGURE=		yes
USE_GNU_CONFIGURE_HOST=	no
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf gmake perl:run
USE_LANGUAGES=		c
GNU_CONFIGURE_PREFIX=	${GHC_PREFIX}

.include "../../mk/bsd.prefs.mk"

GHC_PREFIX=			${PREFIX}/${GHC_SUBPREFIX}
CFLAGS+=			-fPIC
LDFLAGS+=			${COMPILER_RPATH_FLAG}${PREFIX}/lib  -L${PREFIX}/lib
LDFLAGS+=			${COMPILER_RPATH_FLAG}${GHC_PREFIX}/lib  -L${GHC_PREFIX}/lib


CONFIGURE_ARGS+=	--with-gcc=${CC:Q}
CONFIGURE_ARGS+=	--prefix=${GHC_PREFIX:M*:Q}
CONFIGURE_ARGS+=	--with-iconv-includes=${BUILDLINK_PREFIX.iconv}/include
CONFIGURE_ARGS+=	--with-iconv-libraries=${BUILDLINK_PREFIX.iconv}/lib
CONFIGURE_ARGS+=	--with-curses-includes=${BUILDLINK_PREFIX.curses}/include
CONFIGURE_ARGS+=	--with-curses-libraries=${BUILDLINK_PREFIX.curses}/lib


CONFIGURE_ENV+=		ac_cv_path_fp_prog_ar=${AR:Q}
CONFIGURE_ENV+=		PerlCmd=${PERL5:Q}

.for stage in 0 1 3
CONFIGURE_ENV+=		CONF_CC_OPTS_STAGE${stage}=${CFLAGS:M*:Q}
CONFIGURE_ENV+=		CONF_GCC_LINKER_OPTS_STAGE${stage}=${CFLAGS:M*:Q}
CONFIGURE_ENV+=		CONF_LD_LINKER_OPTS_STAGE${stage}=${LDFLAGS:M*:Q}
.endfor



do-configure:
	#${RUN} cd ${WRKSRC} && ./boot
	${RUN} cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${SH} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}


# We can't use static PLIST because the package installs some files whose
# names are randomly generated (e.g. lib/${PKGNAME}/package.conf.d/*.conf)
GENERATE_PLIST+= \
	cd ${DESTDIR}/${PREFIX} && \
		${FIND} * \( -type f -o -type l \) | ${SORT} -d;

CHECK_SHLIBS_SKIP+=		ghc710/*/libHS*-ghc${PKGVERSION_NOREV}.*
CHECK_SHLIBS_SKIP+=		ghc710/lib/ghc-${PKGVERSION_NOREV}/*

.include "../../mk/bsd.prefs.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/ghc7/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/binutils/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../lang/libLLVM/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/hs-hscolour/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
