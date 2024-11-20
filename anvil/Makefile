# $NetBSD$

DISTNAME=	anvil-src-v0.3
PKGNAME=	${DISTNAME:S,-src-v,-,}
CATEGORIES=	editors
MASTER_SITES=	http://anvil-editor.net/releases/

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	http://anvil-editor.net/
COMMENT=	Plan 9 acme-like editor written in Go
LICENSE=	mit

USE_LANGUAGES=	c
USE_TOOLS+=	zip

GO_VERSION_REQD+=	123
GO_MODULES_FILES=	${WRKSRC}/anvil/src/anvil/go.mod

PATCH_DIST_STRIP=	-p1

WRKSRC=	${WRKDIR}/${DISTNAME}/anvil/src/anvil

post-extract:
	${CP} ${WRKSRC}/fs_linux.go ${WRKSRC}/fs_netbsd.go

MAKE_ENV+=	CGO_LDFLAGS=${CGO_LDFLAGS:Q}

pre-build:
	cd ${WRKDIR}/.goproxy/gioui.org/\@v/ && \
	unzip v0.6.0.zip && \
	cd gioui.org\@v0.6.0 && \
	patch ${PATCH_DIST_ARGS} < ${PKGDIR}/kev-patches/patch-app_egl__wayland.go && \
	patch ${PATCH_DIST_ARGS} < ${PKGDIR}/kev-patches/patch-app_egl__x11.go && \
	patch ${PATCH_DIST_ARGS} < ${PKGDIR}/kev-patches/patch-app_internal_xkb_xkb__unix.go && \
	patch ${PATCH_DIST_ARGS} < ${PKGDIR}/kev-patches/patch-app_os__unix.go && \
	patch ${PATCH_DIST_ARGS} < ${PKGDIR}/kev-patches/patch-app_os__wayland.go && \
	patch ${PATCH_DIST_ARGS} < ${PKGDIR}/kev-patches/patch-app_os__x11.go && \
	patch ${PATCH_DIST_ARGS} < ${PKGDIR}/kev-patches/patch-gpu_headless_headless__egl.go && \
	patch ${PATCH_DIST_ARGS} < ${PKGDIR}/kev-patches/patch-internal_egl_egl.go && \
	patch ${PATCH_DIST_ARGS} < ${PKGDIR}/kev-patches/patch-internal_egl_egl__unix.go && \
	patch ${PATCH_DIST_ARGS} < ${PKGDIR}/kev-patches/patch-internal_gl_gl__unix.go && \
        cd .. && zip -r v0.6.0.zip gioui.org\@v0.6.0

.include "go-modules.mk"

.include "../../devel/wayland/buildlink3.mk"
#.include "../../wip/libglvnd/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../lang/go/go-module.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
