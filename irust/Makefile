# $NetBSD$

GITHUB_PROJECT=	IRust
GITHUB_TAG=	refs/tags/irust@1.77.1
DISTNAME=	irust-1.77.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=sigmaSd/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sigmaSd/IRust/
COMMENT=	Cross Platform Rust Repl
LICENSE=	mit

CARGO_INSTALL_ARGS?=	install --path crates/irust --root ${DESTDIR}${PREFIX} ${DEFAULT_CARGO_ARGS}

WRKSRC=		${WRKDIR}/IRust-irust-1.77.1
USE_LANGUAGES=	c

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
