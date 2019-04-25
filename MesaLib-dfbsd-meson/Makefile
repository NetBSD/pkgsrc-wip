# $NetBSD: Makefile,v 1.19 2019/04/11 15:52:08 maya Exp $

# 2019-04-24	i965: fix icelake performance query enabling
COMMIT_ID=	f15409ee5539579c227fa916d410945b0516d712

# 2019-04-24	iris: Split iris_flush_and_dirty_for_history into two helpers.
# COMMIT_ID=	21688a306b299ae7214f4fb139a6813e0018c0a8

# 2019-04-23	intel/isl: Resize clear color buffer to full cacheline
# COMMIT_ID=	f2041d2a9266ec14270b6da9bf9ce2b54d555ebd

# 2019-04-23	intel/fs: Fix D to W conversion in opt_combine_constants
# COMMIT_ID=	21223acf7d5b39e5eb2b248330519cdbee3e63e8

# 2019-04-23	gallium: replace drm_driver_descriptor::configuration with driconf_xml
# COMMIT_ID=	d8b296d3ad96cb04ee57234a0b1a6a046e08a1a7

# 2019-04-23	st/mesa/radeonsi: fix race between destruction of types and shader compilation
# COMMIT_ID=	a6b7068ff5fbf4694a45a6e07adac5047e574514

# 2019-04-23	radv: Add adaptive_sync driconfig option and enable it by default.
# COMMIT_ID=	3844ed8d44677588bc29d470d0b41ef7816591b

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
