# $NetBSD: Makefile,v 1.19 2013/06/25 12:48:32 outpaddling Exp $

DISTNAME=	meep-1.2
CATEGORIES=	science
MASTER_SITES=	http://ab-initio.mit.edu/meep/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://ab-initio.mit.edu/meep/
COMMENT=	FDTD simulation software to model electromagnetic systems
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++ fortran77

CONFIGURE_ARGS+=--with-libctl=${BUILDLINK_PREFIX.libctl}/share/libctl

MESSAGE_SUBST+=         PREFIX=${PREFIX:Q}

TEST_TARGET=	check

# ERROR: file: "libguile-srfi-srfi-1-v-3", message: "file not found"
# Why does this have no effect?  No sign of it in config.log.
# LDFLAGS+=	${LINKER_RPATH_FLAG}${PREFIX}/lib

# Temporary hack until I figure out how to properly tweak LDFLAGS
# Why doesn't COMPILER_RPATH_FLAG work here?  ( expands to -L )
# Doesn't fix the libguile issue anyway
# SUBST_CLASSES+=		ldflags
# SUBST_STAGE.ldflags=	post-configure
# SUBST_FILES.ldflags=	Makefile
# SUBST_SED.ldflags=	-e "s|-L${PREFIX}/lib|-L${PREFIX}/lib -Wl,-rpath,${PREFIX}/lib|g"

.include "../../mk/bsd.prefs.mk"

# Hack to work around problem finding libguile*.dylib
# Darwin needs libguile with a .so suffix and LD_LIBRARY_PATH to include
# Latest seems to only need LD_LIBRARY_PATH
# ${LOCALBASE}/lib
.if ${OPSYS} == "Darwin"
#.for l in ${PREFIX}/lib/libguile-srfi-srfi-*.dylib
#post-install:
#	${CP} ${l} ${l%.dylib}.so
#.endfor
.endif

.include "../../wip/mpb/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../math/harminv/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
