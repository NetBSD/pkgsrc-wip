# $NetBSD$

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	presenterm-0.11.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mfontanini/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mfontanini.github.io/presenterm/
COMMENT=	Markdown terminal slideshow tool
LICENSE=	2-clause-bsd

USE_LANGUAGES=		c
CARGO_FEATURES+=	sixel

.include "cargo-depends.mk"
.include "../../graphics/libsixel/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
