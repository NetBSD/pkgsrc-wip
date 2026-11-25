# $NetBSD: Makefile,v 1.2 2026/08/23 20:21:02 ci4ic4 Exp $

DISTNAME=	zellij-0.46.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=zellij-org/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://zellij.dev/
COMMENT=	Terminal workspace with batteries included
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.92.0
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config gmake perl

# zellij-terminal (winit/glutin) dlopen()s libX11, libxkbcommon, libEGL et al.
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${PREFIX}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${X11BASE}/lib

.include "../../lang/rust/cargo.mk"
.include "../../mk/mesa.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
