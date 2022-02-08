# $NetBSD$

DISTNAME=	wordle-0.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=conradludgate/}
GITHUB_TAG=	bffaaa8

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/conradludgate/wordle
COMMENT=	The wordle game, in rust
#LICENSE=	unclear

WRKSRC=		${WRKDIR}/wordle-bffaaa891fecb0c73509113547a835d9b3968b6d

INSTALLATION_DIRS=	bin

.include "cargo-depends.mk"

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL} ${WRKSRC}/target/release/wordle \
		${DESTDIR}/${PREFIX}/bin/wordle

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
