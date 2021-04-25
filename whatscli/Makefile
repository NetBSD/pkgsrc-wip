# $NetBSD$

DISTNAME=	whatscli-1.0.7
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=normen/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/normen/whatscli
COMMENT=	Command line interface for WhatsApp
LICENSE=	mit

GO_BUILD_PATTERN+=	.

INSTALLATION_DIRS+=	share/doc/whatscli

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/whatscli

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
