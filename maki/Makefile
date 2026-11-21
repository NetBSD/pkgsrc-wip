# $NetBSD$

DISTNAME=	maki-0.7.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=tontinton/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tontinton/maki/
COMMENT=	Efficient, extenable AI coding agent
LICENSE=	mit

USE_LANGUAGES=	c c++

CARGO_GITHUB_CRATES+=	crossterm-rs crossterm 94ed7154e35d24a2f643c61760e1eb05b8ca9e63
CARGO_GITHUB_CRATES+=	tontinton syntect 01df275f6f25da670e5ba5b7128cb89d03795119

INSTALLATION_DIRS+=	share/doc/maki

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/maki

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
