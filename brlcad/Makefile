# $NetBSD$

DISTNAME=	brlcad-7.26.0
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=brlcad/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://brlcad.org/
COMMENT=	Cross-platform solid modeling system
LICENSE=	gnu-lgpl-v2.1 AND modified-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config wish flex perl awk
USE_LANGUAGES=	c c++ fortran

# brlcad uses modified mundled tools and libraries (openNURBS, lemon, ...)
# tools like adaptagrams (libavoid) are unused code for years and no longer
# compatible with existing libraries
CMAKE_ARGS+=	-DBRLCAD_BUNDLED_LIBS=ON

# brlcad must be installed into subprefix as it has conflicting files and it
# will try overwrite them. brlcad will also blacklist existing libraries in
# install subprefix
BRLCAD_PREFIX=		${PREFIX}/brlcad
CMAKE_INSTALL_PREFIX=	${BRLCAD_PREFIX}

# Pass RPATH out of standard prefix
LDFLAGS+=	${COMPILER_RPATH_FLAG}${BRLCAD_PREFIX:Q}/lib
LDFLAGS+=	${COMPILER_RPATH_FLAG}${BRLCAD_PREFIX:Q}/lib/libgcv_plugins

# Allow RPATH out of standard prefix
BUILDLINK_PASSTHRU_DIRS+=	${BRLCAD_PREFIX:Q}
BUILDLINK_PASSTHRU_RPATHDIRS+=	${BRLCAD_PREFIX:Q}

PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libanalyze.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/librt.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libfft.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libfb.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libdm.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libmultispectral.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/liboptical.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libicv.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libpkg.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libgcv.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libged.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libgm.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libwdb.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libpc.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libbn.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libbu.pc.in
PKGCONFIG_OVERRIDE+=	misc/pkgconfig/libbrlcad.pc.in
PKGCONFIG_OVERRIDE+=	src/other/libpng/scripts/libpng.pc.in
PKGCONFIG_OVERRIDE+=	src/other/libpng/libpng.pc.in
PKGCONFIG_OVERRIDE+=	src/other/libz/zlib.pc.in

# What else?
NOT_PAX_MPROTECT_SAFE+=	brlcad/bin/mged

BUILD_DEPENDS+=	astyle-[0-9]*:../../devel/astyle
# BUILD_DEPENDS+=	lemon-[0-9]*:../../devel/lemon # built in
# BUILD_DEPENDS+=	re2c-[0-9]*:../../devel/re2c # built in
BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt # for xsltproc
BUILD_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint
BUILD_DEPENDS+=	swig-[0-9]*:../../devel/swig
BUILD_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen

# brlcad builds intermediate tools and uses it to process files to be built
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/lib

BUILDLINK_TRANSFORM+=	rm:-Werror # unused-but-set-variable, deprecated-declarations ..
BUILDLINK_TRANSFORM+=	rm:-pedantic rm:-pedantic-errors # C99 style comments..

REPLACE_BASH+=		sh/footer.sh
REPLACE_BASH+=		sh/fs2org.sh

REPLACE_PYTHON+=	misc/flawfinder
REPLACE_PYTHON+=	misc/svn2git/svnlog2csv
REPLACE_PYTHON+=	src/conv/intaval-g.py
REPLACE_PYTHON+=	src/other/freetype/builds/mac/ascii2mpw.py
REPLACE_PYTHON+=	src/other/freetype/src/tools/chktrcmp.py
REPLACE_PYTHON+=	src/other/freetype/src/tools/docmaker/docbeauty.py
REPLACE_PYTHON+=	src/other/freetype/src/tools/docmaker/docmaker.py
REPLACE_PYTHON+=	src/other/freetype/src/tools/glnames.py
REPLACE_PYTHON+=	src/other/stepcode/misc/flawfinder
REPLACE_PYTHON+=	src/other/stepcode/misc/wiki-scripts/update-matrix.py
REPLACE_PYTHON+=	src/other/stepcode/src/exp2python/python/setup.py

REPLACE_INTERPRETER+=	awk
REPLACE.awk.old=	.*awk
REPLACE.awk.new=	${AWK}
REPLACE_FILES.awk=	src/other/freetype/builds/atari/deflinejoiner.awk

REPLACE_PERL+=		src/proc-db/metaballs.pl
REPLACE_PERL+=		src/proc-db/spiral.pl

TEST_TARGET=		test check unit regress

benchmark: build
	${RUN}${_ULIMIT_CMD}						\
		cd ${WRKSRC} &&						\
		${PKGSRC_SETENV} ${TEST_ENV} ${MAKE_PROGRAM}		\
			${MAKE_FLAGS} ${TEST_MAKE_FLAGS} benchmark

# .include "../../wip/tk-itk3/buildlink3.mk" # built-in
# .include "../../wip/tkpng/buildlink3.mk" # built-in
# .include "../../wip/tcl-iwidgets/buildlink3.mk" # built-in
# .include "../../wip/tkhtml3/buildlink3.mk" # built-in
# .include "../../devel/tinycthread/buildlink3.mk" # built-in
# .include "../../graphics/adaptagrams/buildlink3.mk" # not any longer compatible, unused by upstream
.include "../../graphics/freetype2/buildlink3.mk"
# .include "../../graphics/netpbm/buildlink3.mk" # built-in
# .include "../../graphics/png/buildlink3.mk" # built-in
.include "../../lang/python/application.mk"
# .include "../../lang/tcl/buildlink3.mk" # built-in
# .include "../../mk/terminfo.buildlink3.mk" # built-in
.include "../../x11/libXext/buildlink3.mk"
# .include "../../x11/tk/buildlink3.mk" # built-in
# .include "../../x11/tktable/buildlink3.mk" # built-in
.include "../../mk/bsd.pkg.mk"
