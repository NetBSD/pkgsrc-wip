# $NetBSD: Makefile,v 1.8 2015/09/07 19:16:42 jonthn Exp $

DISTNAME=	Bear-3.1.5.20260103
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rizsotto/}
GITHUB_TAG=	a468baec8a18e795f446c336126d4cb2a19dcfe7

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rizsotto/Bear
COMMENT=	Tool to generate compilation database
LICENSE=	gnu-gpl-v3

#USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/bear ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/man/bear.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "cargo-depends.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
