# $NetBSD$

GITHUB_TAG=	2023-02-13
DISTNAME=	rust-analyzer-0.3.1402
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rust-lang/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://rust-analyzer.github.io/
COMMENT=	LSP server for the Rust programming language
LICENSE=	apache-2.0

INSTALLATION_DIRS=	bin

.include "cargo-depends.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rust-analyzer \
		${DESTDIR}${PREFIX}/bin/

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
