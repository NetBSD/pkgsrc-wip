# $NetBSD$

DISTNAME=	halloy-2024.12
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=squidowl/}
GITHUB_PROJECT=	halloy
GITHUB_TAG=	refs/tags/${PKGVERSION_NOREV}
WRKSRC=		${WRKDIR}/halloy-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://halloy.squidowl.org/
COMMENT=	IRC application written in Rust
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

.include "cargo-depends.mk"

# halloy uses -dev / git snapshot versions of iced,
# which are not available as crates
SUBST_CLASSES+=			iced-release
SUBST_STAGE.iced-release=	post-extract
SUBST_MESSAGE.iced-release=	Switch to a published version of iced
SUBST_FILES.iced-release=	Cargo.lock Cargo.toml
SUBST_SED.iced-release=		-e 's;0.13.0-dev;0.13.0;g'

# => Checking for missing run-time search paths in halloy-2024.12
# ERROR: bin/halloy: missing library: libasound.so.2
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.alsa-lib}/lib

## https://github.com/rust-windowing/winit/issues/3603
# thread 'main' panicked at /usr/pkgsrc/wip/halloy/work/vendor/iced_winit-0.13.0/src/program.rs:192:10:
# Create event loop: NotSupported(NotSupportedError)
# note: run with `RUST_BACKTRACE=1` environment variable to display a backtrace
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
#RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
#RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
