# $NetBSD$

DISTNAME=	v5.0.0-rc5
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=DNSControl/}
GITHUB_PROJECT=	dnscontrol
GITHUB_TAG=	refs/tags/v5.0.0-rc5
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://dnscontrol.org/
COMMENT=	Opinionated platform for managing DNS configuration
LICENSE=	mit

WRKSRC=		${WRKDIR}/dnscontrol-5.0.0-rc5
USE_LANGUAGES=	c

INSTALLATION_DIRS+=	bin

# Only build dnscontrol, not the development tools `build', `generate',
# and `validate', which appear to be not terribly useful to install.
GO_BUILD_PATTERN=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
