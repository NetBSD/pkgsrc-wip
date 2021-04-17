# $NetBSD$

DISTNAME=	uq-0.1.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=lostutils/}
GITHUB_PROJECT=	uq
GITHUB_TAG=	118bc2f3b1cf292afdffbc1cb4415d150b323165

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lostutils/uq/
COMMENT=	Simple, user-friendly alternative to sort, uniq
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+= c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/uq ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
