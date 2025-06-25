# $NetBSD$

DISTNAME=	edit-1.2.0
PKGNAME=	ms${DISTNAME}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=microsoft/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/microsoft/edit/
COMMENT=	Simple editor for simple needs
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	# none
RUST_REQ=	1.87

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
