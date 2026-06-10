# $NetBSD$

DISTNAME=	brush-shell-v0.4.0
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	shell
MASTER_SITES=	${MASTER_SITE_GITHUB:=reubeno/}
GITHUB_PROJECT=	brush
GITHUB_TAG=	refs/tags/brush-shell-v0.4.0

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/reubeno/brush/
COMMENT=	brush (Bo(u)rn(e) RUsty SHell) is a modern bash- and POSIX- compatible shell written in Rust
LICENSE=	mit

WRKSRC=		${WRKDIR}/brush-brush-shell-v0.4.0

RUST_REQ=	1.88.0
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

PKG_SHELL=	bin/brush

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/brush \
		${DESTDIR}${PREFIX}/bin

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
