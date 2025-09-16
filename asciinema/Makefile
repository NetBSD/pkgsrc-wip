# $NetBSD$

DISTNAME=	asciinema-3.0.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=asciinema/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/asciinema/asciinema/
COMMENT=	Terminal session recorder, streamer and player
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
