e $NetBSD: Makefile,v 1.19 2019/04/11 15:52:08 maya Exp $

# 2019-05-01	util: move #include out of #if linux
COMMIT_ID=	70da00ffd65e56c8c8cc6ecfcec462fb52ee5102

# 2019-05-01	gitlab-ci: build vulkan drivers in clang build
# COMMIT_ID=	47f419d0b37721776785a54005783ef6fe836d66

# 2019-04-30	egl: return correct error code for a case req ver < 3 with forward-compatible
# COMMIT_ID=	5c581b3dd6979b79cb3e3ab8e2e03b442e6ecb0d

# 2019-04-30	radeonsi/nir: call radeonsi nir opts before the scan pass
# COMMIT_ID=	90f3bf7437eb735bf51d8fcbfbb0adeed9cfcf89

# 2019-04-30	swr/rast: early exit on empty triangle mask
# COMMIT_ID=	4c68acba3749b84c95c0e8751a00eeb1e820d6f4

# 2019-04-30	st/va: properly set stride and offset in vlVaDeriveImage
# COMMIT_ID=	0e3a348bec436b9d949e85574e363a1fe0e7683c

# 2019-04-29	i965: Re-enable fast color clears for GEN11.
# COMMIT_ID=	11518384c465b9f4a7ef19e2cef068bba7d66b63

# 2019-04-27	radv: add missing VEGA20 chip in radv_get_device_name()
# COMMIT_ID=	07745f94948874c875dac924e055a11ee96beb5b

# 2019-04-26	vc4: Fall back to renderonly if the vc4 driver doesn't have v3d.
# COMMIT_ID=	edb04953c8b8520108f333b1e289f18719a7d597

# 2019-04-26	swr/rast: enforce use of tile offsets
# COMMIT_ID=	8bfb34fd0adf23fdb73cf5e4253b42cb2da58188

# 2019-04-26	llvmpipe: Always return some fence in flush (v2)
# COMMIT_ID=	e8bf4efcebf0d860dec3a38be3388aba035b0d1b

# 2019-04-25	nir: fix bit_size in lower indirect derefs.
# COMMIT_ID=	d946cbe9f54a1b733e0bdec2423ae47d408114fb

# 2019-04-25	glsl: fix shader_storage_blocks_write_access for SSBO block arrays (v2)
# COMMIT_ID=	c5f65bfe6c9b82925d65ba677664cfc063a9b96c

# 2019-04-25	freedreno/a6xx: sample-shading support
# COMMIT_ID=	7a57cfbed695c48915fdb3d7bec37505d3f18e81

PORTNAME=	mesa		

DISTNAME=	${PORTNAME}-${COMMIT_ID}
PKGNAME=	MesaLib-19.1.0
# PKGREVISION=	1
CATEGORIES=	graphics x11
MASTER_SITES=	http://cgit.freedesktop.org/mesa/${PORTNAME}/snapshot/

# DISTNAME=	mesa-18.3.3
# PKGNAME=	${DISTNAME:S/mesa/MesaLib/}
# CATEGORIES=	graphics x11
# MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/
# MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mesa3d.org/
COMMENT=	The Mesa 3D Graphics Library
LICENSE=	mit

# GNU_CONFIGURE=	yes
# USE_TOOLS+=	autoconf automake autoreconf bison pkg-config gmake flex
USE_TOOLS+=	bison pkg-config gmake flex
USE_LANGUAGES=	c99 c++
# USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	src/egl/main/egl.pc.in
PKGCONFIG_OVERRIDE+=	src/gallium/targets/d3dadapter9/d3d.pc.in
PKGCONFIG_OVERRIDE+=	src/gallium/targets/osmesa/osmesa.pc.in
PKGCONFIG_OVERRIDE+=	src/gallium/targets/xa/xatracker.pc.in
PKGCONFIG_OVERRIDE+=	src/gbm/main/gbm.pc.in
PKGCONFIG_OVERRIDE+=	src/glx/windows/windowsdriproto.pc.in
PKGCONFIG_OVERRIDE+=	src/mapi/es1api/glesv1_cm.pc.in
PKGCONFIG_OVERRIDE+=	src/mapi/es2api/glesv2.pc.in
PKGCONFIG_OVERRIDE+=	src/mesa/drivers/dri/dri.pc.in
PKGCONFIG_OVERRIDE+=	src/mesa/drivers/osmesa/osmesa.pc.in
PKGCONFIG_OVERRIDE+=	src/mesa/gl.pc.in

CONFIGURE_ARGS+=		--enable-shared-glapi
MESON_ARGS+=			-Dshared-glapi=true

# Work around a buildlink and/or libtool bug:
# In the libtool install/relink stage, if we want to link with two static
# archives named libglapi.la but in different directories, bad things happen.
SUBST_CLASSES+=			wrapper-bug
SUBST_STAGE.wrapper-bug=	pre-configure
SUBST_MESSAGE.wrapper-bug=	Renaming non-shared libglapi.la in Makefiles
SUBST_FILES.wrapper-bug=	src/gallium/targets/libgl-xlib/Makefile.am
SUBST_FILES.wrapper-bug+=	src/gallium/targets/osmesa/Makefile.am
SUBST_FILES.wrapper-bug+=	src/glx/Makefile.am
SUBST_FILES.wrapper-bug+=	src/mapi/Makefile.am
SUBST_FILES.wrapper-bug+=	src/mesa/drivers/osmesa/Makefile.am
SUBST_FILES.wrapper-bug+=	src/mesa/drivers/x11/Makefile.am
SUBST_SED.wrapper-bug=		-e 's,shared-glapi/libglapi\.la,shared-glapi/libglapi_tmp_rename.la,g'
SUBST_SED.wrapper-bug+=		-e 's,shared_glapi_libglapi_la,shared_glapi_libglapi_tmp_rename_la,g'
SUBST_SED.wrapper-bug+=		-e 's,libglapi\.la,libglapi_impl.la,g'
SUBST_SED.wrapper-bug+=		-e 's,libglapi_la,libglapi_impl_la,g'
SUBST_SED.wrapper-bug+=		-e 's,libglapi_tmp_rename\.la,libglapi.la,g'
SUBST_SED.wrapper-bug+=		-e 's,libglapi_tmp_rename_la,libglapi_la,g'

# Replace /etc/drirc.d with ${PREFIX}/etc/drirc.d
SUBST_CLASSES+=			drirc
SUBST_STAGE.drirc=		pre-configure
SUBST_MESSAGE.drirc=		Fixing hardcoded /etc/drirc.d references
SUBST_FILES.drirc+=		src/util/xmlconfig.c
SUBST_SED.drirc+=		 -e 's|/etc|${PREFIX}/etc|g'

CFLAGS.SunOS+=		-D__EXTENSIONS__ -D_POSIX_PTHREAD_SEMANTICS
CXXFLAGS.SunOS+=	-Drestrict=__restrict__
LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"
.include "options.mk"

.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-glx-read-only-text
MESON_ARGS+=		-Dglx-read-only-text=true
.endif

PYTHON_FOR_BUILD_ONLY=	yes
BUILD_DEPENDS+=		${PYPKGPREFIX}-mako-[0-9]*:../../devel/py-mako
# needed to build vulkan support
BUILD_DEPENDS+=		${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}
.include "../../lang/python/tool.mk"

# Handle platforms without exp2
.if !empty(MACHINE_PLATFORM:MNetBSD-[1-5].*-*)
CPPFLAGS+=	-Dexp2\(x\)=exp\(\(x\)\*M_LN2\)
CPPFLAGS+=	-Dexp2f\(x\)=expf\(\(x\)\*M_LN2\)
.endif

# Work around Xorg segfaulting in radeon driver due to wrong alloca being used
CFLAGS.NetBSD+=		-Dalloca=__builtin_alloca
CXXFLAGS.NetBSD+=	-Dalloca=__builtin_alloca

# Autotools is being phased out
CONFIGURE_ARGS+=		--enable-autotools

pre-configure:
	touch ${WRKSRC}/src/glx/apple_dummy.cpp
# 	cd ${WRKSRC} && autoreconf -vif

DRIRC_DIR=		${PKG_SYSCONFDIR}/drirc.d
EGDIR=			${PREFIX}/share/examples/mesa
OWN_DIRS+=		${DRIRC_DIR}
INSTALLATION_DIRS+=	${EGDIR}
CONF_FILES+=		${EGDIR}/00-mesa-defaults.conf	\
			  ${DRIRC_DIR}/00-mesa-defaults.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/util/00-mesa-defaults.conf ${DESTDIR}${EGDIR}

# FreeBSD bug 225414 --build-id=sha1 used by i965
.if ${OPSYS} == "FreeBSD"
PKG_LD=			${PREFIX}/bin/gld
LDFLAGS+=		-fuse-ld=${PKG_LD:Q}
_WRAP_EXTRA_ARGS.CXX+=	-fuse-ld=${PKG_LD:Q}
CWRAPPERS_APPEND.cxx+=	-fuse-ld=${PKG_LD:Q}
.include "../../devel/binutils/buildlink3.mk"
.endif

# Meson
CFLAGS+=	-Wno-return-type
.include "../../devel/py-meson/build.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
