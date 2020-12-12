# $NetBSD$

DISTNAME=	consul-1.9.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.consul.io/
COMMENT=	Tool for service discovery, monitoring and configuration
LICENSE=	mpl-2.0

EXTRACT_USING=	bsdtar

GITHUB_TAG=	v${PKGVERSION_NOREV}

.include "go-modules.mk"

GO_BUILD_PATTERN=	.
CHECK_RELRO_SKIP+=	bin/consul

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/consul ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
