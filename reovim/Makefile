# $NetBSD$

DISTNAME=	reovim-0.7.8
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=ds1sqe/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ds1sqe/reovim/
COMMENT=	Rust-powered neovim-like text editor
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/reovim \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
