# $NetBSD$
#

DISTNAME=		nats-server-2.1.8
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=nats-io/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

HOMEPAGE=		https://nats.io/
COMMENT=		Simple, secure and high performance messaging system
LICENSE=		apache-2.0

GO_BUILD_PATTERN=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
