# $NetBSD$

DISTNAME=	teamtype-0.9.2
CATEGORIES=	net editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=teamtype/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/teamtype/teamtype/
COMMENT=	Peer-to-peer, editor-agnostic collaborative editing
LICENSE=	gnu-agpl-v3

USE_LANGUAGES=	c

CARGO_WRKSRC=	${WRKSRC}/crates/teamtype

INSTALLATION_DIRS+=	share/doc/teamtype

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${DESTDIR}${PREFIX}/share/doc/teamtype

.include "cargo-depends.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
