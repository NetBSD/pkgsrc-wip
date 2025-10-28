# $NetBSD$

DISTNAME=	gurk-0.7.1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=boxdot/}
GITHUB_PROJECT=	gurk-rs
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/boxdot/gurk-rs/
COMMENT=	Signal Messenger client for terminal
LICENSE=	mit #gnu-agpl-v3

WRKSRC=		${WRKDIR}/gurk-rs-0.7.1

USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config gmake perl

# Depends on an unpublished crates. Can't use cargo.mk to fetch it.
PRESAGE_REV=		0da7b57746b827bfb310f98a10a29e73d508e742
POKSHO_REV=		e46841ea2c1ad03bc5113eba267ac1543689d031
CURVE25519-DALEK_REV=	fa033980129e3d7b806803b3f1a2a04399ea6fb

DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	presage-${PRESAGE_REV}.tar.gz
DISTFILES+=	poksho-${POKSHO_REV}.tar.gz
DISTFILES+=	curve25519-dalek-${CURVE25519-DALEK_REV}.tar.gz

SITES.presage-${PRESAGE_REV}.tar.gz=			-${MASTER_SITE_GITHUB:=whisperfish/}presage/archive/${PRESAGE_REV}.tar.gz
SITES.poksho-${POKSHO_REV}.tar.gz=			-${MASTER_SITE_GITHUB:=signalapp/}libsignal/archive/${POKSHO_REV}.tar.gz
SITES.curve25519-dalek-${CURVE25519-DALEK_REV}.tar.gz=	-${MASTER_SITE_GITHUB:=signalapp/}curve25519-dalek/archive/${CURVE25519-DALEK_REV}.tar.gz

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
