# $NetBSD: Makefile,v 1.20 2019/04/25 07:32:56 maya Exp $

# 2019-05-12	radv: Do not use extra descriptor space for the 3rd plane.
COMMIT_ID=	f53ebfb4503a1ae054539df1c414b86c3b1966d9

# 2019-05-11	nir: Fix wrong sign in lower_rcp
# COMMIT_ID=	974c4d679c23373dbed386c696e3e3bc1bfa23ae

# 2019-05-10	intel: drop misleading driver name from gen_get_device_info()
# COMMIT_ID=	7b2468bf6e58b0b178f8f498fca92c9cc0a71edb

# 2019-05-10	radv: clear vertex bindings while resetting command buffer
# COMMIT_ID=	24af0f1318967e20a8c5d7f3559389c341a0a11c

# 2019-05-09	lima: fix tile buffer reloading
# COMMIT_ID=	e44a4bae52f8d835bd7d4b740cb688f59d03cced

# 2019-05-08	iris: Reorganise execbuf to have a single point of failure
# COMMIT_ID=	8b8125646991fb7e923821bafea9bec3ba355b42

# 2019-05-08	kmsro: add _dri.so to two of the kmsro drivers.
# COMMIT_ID=	0a42d5b98bc3083e20475eb1ecea20f9b876269d

# 2019-05-07	Revert "glx: Fix synthetic error generation in __glXSendError"
# COMMIT_ID=	a01b393c397c846345f03f76f1167dd667e0ee96

# 2019-05-04	panfrost/midgard: iabs cannot run on mul
# COMMIT_ID=	68238732462bb044282ffbeb6cb08b96c7ff7805

# 2019-05-03	st/va: check resource_get_info nullity in vlVaDeriveImage
# COMMIT_ID=	8cd71f399e73c5d87e9162cc74da76e317a9f41f

# 2019-05-03	radv: apply the indexing workaround for atomic buffer operations on GFX9
# COMMIT_ID=	4f18c43d1df64135e8968a7d4fbfd2c9918b76ae

# 2019-05-03	anv: fix crash when application does not provide push constants
# COMMIT_ID=	80dc78407d0d1e03ceddf8889b217e8fd113568d

# 2019-05-02	anv: Stop including POS in FS input limits
# COMMIT_ID=	be7e9870d620460a91e8fbdbb8bf39b5c462aed3

# 2019-05-02	docs: fixup mistake in contents
# COMMIT_ID=	96924aa92ecf16cd2145b1a881df37d9162c6ba7

# 2019-05-02	panfrost/midgard: Skip liveness analysis for instructions without dest
# COMMIT_ID=	ad7c9ba0ecb349763ab7fad7bce74f1d47c139e3

# 2019-05-01	util/bitset: Return an actual bool from test macros
# COMMIT_ID=	bf774b56be46d5812868d9f6e7e63437d36754e0

# 2019-05-01	panfrost: Fix blend shader upload
# COMMIT_ID=	09c669260f6d311d0d99f2c63ebd0ec5b68853f8

# 2019-05-01	util: move #include out of #if linux
# COMMIT_ID=	70da00ffd65e56c8c8cc6ecfcec462fb52ee5102

# 2019-05-01	gitlab-ci: build vulkan drivers in clang build
# COMMIT_ID=	47f419d0b37721776785a54005783ef6fe836d66

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
# USE_TOOLS+=	autoconf automake autoreconf bison pkg-config flex
USE_TOOLS+=	bison pkg-config flex
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
SUBST_CLASSES+=		drirc
SUBST_STAGE.drirc=	pre-configure
SUBST_MESSAGE.drirc=	Fixing hardcoded /etc/drirc.d references
SUBST_FILES.drirc+=	src/util/xmlconfig.c
SUBST_SED.drirc+=	-e 's|/etc|${PREFIX}/etc|g'

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
.include "../../devel/meson/build.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
