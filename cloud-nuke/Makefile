# $NetBSD$

DISTNAME=	cloud-nuke-0.1.29
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=gruntwork-io/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gruntwork-io/cloud-nuke
COMMENT=	Clean up cloud accounts by nuking (deleting) all resources within it
LICENSE=	mit

GO_BUILD_PATTERN+=	.

INSTALLATION_DIRS+=	share/doc/cloud-nuke

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/cloud-nuke

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
