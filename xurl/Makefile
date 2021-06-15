# $NetBSD$

DISTNAME=	xurl-0.1.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=squioc/}
GITHUB_PROJECT=	xurl
GITHUB_TAG=	d604d178b88650736d746d2fe15c72e760a5977f

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/squioc/xurl/
COMMENT=	Little tool to manipulate urls
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/xurl ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
