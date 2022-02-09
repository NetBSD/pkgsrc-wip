# $NetBSD$

DISTNAME=	wordle-0.2.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=conradludgate/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/conradludgate/wordle
COMMENT=	The wordle game, in rust
LICENSE=	mit

INSTALLATION_DIRS=	bin

.include "cargo-depends.mk"

do-install:
	${INSTALL} ${WRKSRC}/target/release/wordle \
		${DESTDIR}/${PREFIX}/bin/wordle

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
