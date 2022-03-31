# $NetBSD$

GITHUB_PROJECT=	helix
DISTNAME=	22.03
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=helix-editor/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://helix-editor.com/
COMMENT=	Editor inspired by kakoune / neovim
LICENSE=	mpl-2.0
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../lang/rust/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
