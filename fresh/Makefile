# $NetBSD$

DISTNAME=	fresh-0.4.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=sinelaw/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sinelaw/fresh/
COMMENT=	Terminal-based IDE and text editor with zero configuration
LICENSE=	gnu-gpl-v2

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c c++

CARGO_INSTALL_ARGS=	install --path crates/fresh-editor --root ${DESTDIR}${PREFIX} ${DEFAULT_CARGO_ARGS}

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
