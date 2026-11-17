# $NetBSD$

DISTNAME=	psychic-0.4.1
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_GITHUB:=kshitijl/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://klauria.tech/psychic/
COMMENT=	Smarter file explorer and cd replacement
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_TOOLS+=	cmake

.include "cargo-depends.mk"

.include "../../lang/clang/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
