# $NetBSD$

DISTNAME=	maolan-0.0.20260305
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=maolan/}
GITHUB_TAG=	651fbfa6f6bd543fa92094f893ff48f2cf7e0a39

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/maolan/maolan/
COMMENT=	Rust DAW focused on recording, editing, routing, and plugin hosting
LICENSE=	2-clause-bsd

USE_TOOLS+=	pkg-config

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.lilv}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.suil}/lib

.include "cargo-depends.mk"

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
.include "../../audio/lilv/buildlink3.mk"
.endif
.include "../../audio/suil/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
