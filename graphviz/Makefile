# $NetBSD: Makefile,v 1.301 2025/07/13 08:17:38 wiz Exp $

DISTNAME=	graphviz-13.1.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITLAB:=api/v4/projects/4207231/packages/generic/graphviz-releases/${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://www.graphviz.org/
COMMENT=	Graph Drawing Programs from AT&T Research and Lucent Bell Labs
LICENSE=	epl-v1.0

CHECK_FILES_SKIP+=		${PREFIX}/lib/graphviz/config6
CHECK_PORTABILITY_SKIP+=	windows/*

USE_LANGUAGES=		c c++
USE_CC_FEATURES=	c17
USE_CXX_FEATURES=	c++17 unique_ptr

USE_TOOLS+=		automake autoreconf makeinfo bison flex gmake groff pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # has sub-configures
CONFIGURE_ARGS+=	--disable-d
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--disable-go
CONFIGURE_ARGS+=	--disable-guile
CONFIGURE_ARGS+=	--disable-io
CONFIGURE_ARGS+=	--disable-java
CONFIGURE_ARGS+=	--disable-javascript
CONFIGURE_ARGS+=	--disable-man-pdfs
CONFIGURE_ARGS+=	--disable-ocaml
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-php
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-python3
CONFIGURE_ARGS+=	--disable-r
CONFIGURE_ARGS+=	--disable-ruby
CONFIGURE_ARGS+=	--disable-sharp
CONFIGURE_ARGS+=	--enable-ltdl
CONFIGURE_ARGS+=	--enable-rpath
CONFIGURE_ARGS+=	--without-ann
CONFIGURE_ARGS+=	--without-devil
CONFIGURE_ARGS+=	--without-gdiplus
CONFIGURE_ARGS+=	--without-gdk
CONFIGURE_ARGS+=	--without-glade
CONFIGURE_ARGS+=	--without-glitz
CONFIGURE_ARGS+=	--without-glut
CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--without-gtkgl
CONFIGURE_ARGS+=	--without-gtkglext
CONFIGURE_ARGS+=	--without-lasi
CONFIGURE_ARGS+=	--without-ming
CONFIGURE_ARGS+=	--without-qt
CONFIGURE_ARGS+=	--without-smyrna
CONFIGURE_ARGS+=	--with-digcola
CONFIGURE_ARGS+=	--with-expat
CONFIGURE_ARGS+=	--with-fontconfig
CONFIGURE_ARGS+=	--with-freetype2
CONFIGURE_ARGS+=	--with-gts
CONFIGURE_ARGS+=	--with-ipsepcola
CONFIGURE_ARGS+=	--with-ortho
CONFIGURE_ARGS+=	--with-pangocairo
CONFIGURE_ARGS+=	--with-sfdp
CONFIGURE_ARGS+=	--disable-tcl
CONFIGURE_ARGS+=	--with-visio
CONFIGURE_ARGS+=	--with-webp
# build fails when PHP and/or Ruby are also installed
CONFIGURE_ENV+=		ac_cv_prog_PHP=
CONFIGURE_ENV+=		ac_cv_prog_RUBY=

CPPFLAGS+=		-DNO_POSTSCRIPT_ALIAS=1
LDFLAGS.SunOS+=		-lsocket -lnsl

PKGCONFIG_OVERRIDE+=	lib/cdt/libcdt.pc.in
PKGCONFIG_OVERRIDE+=	lib/cgraph/libcgraph.pc.in
PKGCONFIG_OVERRIDE+=	lib/edgepaint/liblab_gamut.pc.in
PKGCONFIG_OVERRIDE+=	lib/expr/libexpr.pc.in
PKGCONFIG_OVERRIDE+=	lib/gvc/libgvc.pc.in
PKGCONFIG_OVERRIDE+=	lib/gvpr/libgvpr.pc.in
PKGCONFIG_OVERRIDE+=	lib/pack/libpack.pc.in
PKGCONFIG_OVERRIDE+=	lib/pathplan/libpathplan.pc.in
PKGCONFIG_OVERRIDE+=	lib/sfdpgen/libsfdp.pc.in
PKGCONFIG_OVERRIDE+=	lib/xdot/libxdot.pc.in

# With lua51 there's a PLIST divergence and it isn't obvious whether
# it's serious or not, or what causes it.
LUA_VERSIONS_INCOMPATIBLE=	51

REPLACE_PERL+=		contrib/dotmcl.pl contrib/dirgraph/dirgraph.pl
REPLACE_PYTHON+=	cmd/dot/dot_sandbox

.include "../../mk/bsd.prefs.mk"

# Override Xaw type configured by user
XAW_TYPE=		standard

.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "powerpc"
# Forces link with -lgomp directly instead of via dlopen()
# so we don't overflow thread-local storage in ld.elf_so
CFLAGS+=		-fopenmp
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}"
.endif

.if ${OPSYS} == "FreeBSD"
SUBST_CLASSES+=		sfflags
SUBST_STAGE.sfflags=	pre-configure
SUBST_MESSAGE.sfflags=	Fixing SF_FLAGS identifier for FreeBSD.
SUBST_FILES.sfflags=	lib/sfio/sfclrlock.c lib/sfio/sfio_t.h lib/sfio/sfio.h
SUBST_FILES.sfflags+=	lib/sfio/sfnew.c lib/sfio/sfopen.c lib/sfio/sfset.c
SUBST_SED.sfflags=	-e 's|SF_FLAGS|SFIO_FLAGS|g'
.endif

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

# Remove temporary files and directories created by re-linking "libgv_lua.la".
post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/lib/graphviz/lua/gv.so \
		${DESTDIR}${PREFIX}/lib/graphviz/tcl/tcl \
		${DESTDIR}${PREFIX}/lib/lua/5.1/gv.so

.include "options.mk"

DEPENDS+=	urw-fonts-[0-9]*:../../fonts/urw-fonts
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.22.0
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gts/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
