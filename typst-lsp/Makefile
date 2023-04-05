# $NetBSD$

DISTNAME=	typst-lsp-0.3.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=nvarner/}
GITHUB_PROJECT=	typst-lsp
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nvarner/typst-lsp/
COMMENT=	Language server for typst
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/typst-lsp ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
