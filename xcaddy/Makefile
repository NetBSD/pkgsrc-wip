# $NetBSD$

DISTNAME=	xcaddy-0.4.5
CATEGORIES=	www
GITHUB_TAG=	v${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=caddyserver/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://caddyserver.com/
COMMENT=	Build Caddy with plugins
LICENSE=	apache-2.0

DEPENDS+=	${GO_PACKAGE_DEP}

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
