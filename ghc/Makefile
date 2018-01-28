# $NetBSD$

DISTNAME=	ghc-7.10.2-src
PKGNAME=	${DISTNAME:S/-src$//}
CATEGORIES=	lang
MASTER_SITES=	http://www.haskell.org/ghc/dist/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

EXTRACT_USING=	gtar

MAINTAINER=	pho@cielonero.org
HOMEPAGE=	http://www.haskell.org/ghc/
COMMENT=	Compiler for the functional language Haskell
LICENSE=	modified-bsd

BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

# By default only extract the primary source, not all of the bootstrap kits.
DISTFILES=	${DEFAULT_DISTFILES}
EXTRACT_ONLY=	${DEFAULT_DISTFILES}
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

GNU_CONFIGURE=		yes
USE_GNU_CONFIGURE_HOST=	no
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf gmake patch perl:run

CONFIGURE_ARGS+=	--with-gcc=${CC:Q}
CONFIGURE_ARGS+=	--with-gmp-includes=${BUILDLINK_PREFIX.gmp}/${BUILDLINK_INCDIRS.gmp:Q}
CONFIGURE_ARGS+=	--with-gmp-libraries=${BUILDLINK_PREFIX.gmp}/${BUILDLINK_LIBDIRS.gmp:Q}
CONFIGURE_ARGS+=	--with-iconv-includes=${BUILDLINK_PREFIX.iconv}/${BUILDLINK_INCDIRS.iconv:Q}
CONFIGURE_ARGS+=	--with-iconv-libraries=${BUILDLINK_PREFIX.iconv}/${BUILDLINK_LIBDIRS.iconv:Q}

CONFIGURE_ENV+=		PerlCmd=${PERL5:Q}
.for stage in 0 1 2
CONFIGURE_ENV+=		CONF_CC_OPTS_STAGE${stage}=${CFLAGS:Q}
CONFIGURE_ENV+=		CONF_GCC_LINKER_OPTS_STAGE${stage}=${LDFLAGS:Q}
.endfor

.include "../../mk/bsd.prefs.mk"

# Darwin's /usr/lib/libffi.dylib is picked up and used, but is the wrong
# version so we force the "system" (pkgsrc) one to be used.  This needs to
# be fixed properly, figuring out how to exclude /usr/lib from the @rpath
# search instead.
.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+= 	--with-system-libffi
CONFIGURE_ARGS+= 	--with-ffi-includes=${BUILDLINK_PREFIX.libffi}/${BUILDLINK_INCDIRS.libffi:Q}
CONFIGURE_ARGS+= 	--with-ffi-libraries=${BUILDLINK_PREFIX.libffi}/${BUILDLINK_LIBDIRS.libffi:Q}
.include "../../devel/libffi/buildlink3.mk"
.endif

# Define the target "pre-configure" and non-standard "bootstrap".
.include "../../wip/ghc/bootstrap.mk"

# Our pre-configure phase installs a bindist of bootstrapping compiler
# directly into TOOLS_DIR so that ./configure can find it.
do-configure:
	${RUN} cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${SH} ./configure ${CONFIGURE_ARGS}
	${RUN} ${RM} -f ${WRKSRC}/mk/build.mk
	${RUN} ${ECHO} "BuildFlavour = quick" >${WRKSRC}/mk/build.mk
	${RUN} ${ECHO} "DYNAMIC_GHC_PROGRAMS = NO" >>${WRKSRC}/mk/build.mk
	${RUN} ${CAT} ${WRKSRC}/mk/build.mk.sample >>${WRKSRC}/mk/build.mk
	${RUN} ${ECHO} "libraries/terminfo_CONFIGURE_OPTS += \
	    --configure-option=--with-curses-includes=${BUILDLINK_PREFIX.curses}/${BUILDLINK_INCDIRS.curses} \
	    --configure-option=--with-curses-libraries=${BUILDLINK_PREFIX.curses}/${BUILDLINK_LIBDIRS.curses}" >> ${WRKSRC}/mk/build.mk

# Substitutions for INSTALL and DEINSTALL that handles package.cache.
FILES_SUBST+=	DISTNAME=${DISTNAME}

# We don't want package.cache to be in the PLIST.
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/${DISTNAME}/package.conf.d/package.cache

# We can't use static PLIST because the package installs some files whose
# names are randomly generated (e.g. lib/${PKGNAME}/package.conf.d/*.conf)
GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
		${FIND} * \( -type f -o -type l \) | ${SORT} -d;

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
