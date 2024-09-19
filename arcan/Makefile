# $NetBSD$

GITHUB_PROJECT=	arcan
DISTNAME=	0.5.5.2
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=letoram/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	coypu+arcan@sdf.org
HOMEPAGE=	https://arcan-fe.com/
COMMENT=	Graphical development toolkit
LICENSE=	modified-bsd AND gnu-gpl-v2 AND gnu-lgpl-v2 AND public-domain

WRKSRC=		${WRKDIR}/arcan-${DISTNAME}
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_CMAKE=	yes
CMAKE_ARG_PATH=	src

PKGCONFIG_OVERRIDE+=	src/platform/cmake/shmif_ext.pc.in
PKGCONFIG_OVERRIDE+=	src/platform/cmake/shmif.pc.in
PKGCONFIG_OVERRIDE+=	src/platform/cmake/shmif_srv.pc.in
PKGCONFIG_OVERRIDE+=	src/platform/cmake/shmif_tui.pc.in

BUILDLINK_TRANSFORM+=	rm:-march=native

# XXX Ruby replace happens too late.
pre-configure: 
	chmod +x ${WRKSRC}/doc/docgen.rb
	cd ${WRKSRC}/doc && ruby${RUBY_VER} ./docgen.rb mangen

.include "../../lang/ruby/buildlink3.mk"
BUILDLINK_DEPMETHOD.${RUBY_BASE}=	build
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
