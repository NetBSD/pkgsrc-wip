# $NetBSD: Makefile,v 1.19 2019/04/11 15:52:08 maya Exp $

# 2019-04-13	nir: add lower_ftrunc
COMMIT_ID=	b6bed115a5efb281b450c749418646b4ea2e7db7

# 2019-04-12	v3d: Use the new lower_to_scratch implementation for indirects on temps.
# COMMIT_ID=	dc402be73e4bbb9b43213a4266b98a46092e3038

# 2019-04-10	lima: implement blit with util_blitter
# COMMIT_ID=	a155c26a66d58d9283b314dce4dd2abb71355349

# 2019-04-10	docs: update calendar, and news item and link release notes for 19.0.2
# COMMIT_ID=	4122f55574f1184e73962135123be1899b1739db

# 2019-04-10	gallium/aux: Report error if loading of a pipe driver fails.
# COMMIT_ID=	6ec9733b9f16e94dc3b3a0e6f9e88bced6955e86

# 2019-04-09	bin: drop unused import from install_megadrivers.py
# COMMIT_ID=	eb699c15750f6e927e666bdd0ef2b6d6aff8a1b9

# 2019-04-08	drisw: Try harder to probe whether MIT-SHM works
# COMMIT_ID=	52426ce4a929f7e1389baf490967fc02357b3f5e

# 2019-03-31	i965: perf: update render basic configs for big core gen9/gen10
# COMMIT_ID=	f0b472b3016c9625e1324fc7f70fc875e5926e00

# 2019-03-30	iris: fix set_sampler_view
# COMMIT_ID=	b2d651b86267f7511e3c4c35d92c0ff72e174bc

# 2019-03-25	freedreno/ir3: Fix operand order for DSX/DSY
# COMMIT_ID=	c7c432738a68d543dc1b73eae895ec4dfacd92b2

# 2019-03-23	spirv: Add an execution environment to the options
# COMMIT_ID=	15012077bceda24cbf38afeda7723c47e1b0d3c3

# 2019-03-22	docs: update freedreno status
# COMMIT_ID=	cdd90a7502e501b0f25d35a2e9715fbe5d09a211

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
