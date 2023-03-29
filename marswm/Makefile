# $NetBSD$

DISTNAME=	marswm-0.3.2
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=jzbor/}
GITHUB_TAG=	cc6f85a80b91c9020aebac0e807b5fe76b141b85

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/jzbor/marswm/
COMMENT=	Modern window manager featuring dynamic tiling
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/mars-relay \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/marsbar \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/marswm \
		${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "NetBSD" || ${X11_TYPE} == "modular"
DEPENDS+=	xrandr-[0-9]*:../../x11/xrandr
.endif

.include "../../lang/rust/cargo.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
