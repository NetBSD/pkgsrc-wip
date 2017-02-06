# $NetBSD$

GITHUB_PROJECT=	caddy
DISTNAME=	v0.9.5
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S/v//}
CATEGORIES=	wip www
MASTER_SITES=	${MASTER_SITE_GITHUB:=mholt/caddy/archive/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=mholt/caddy/}
COMMENT=	general-purpose web server
LICENSE=	apache-2.0

WRKSRC=		${WRKSRC}
GO_DIST_BASE=	${PKGNAME_NOREV}
GO_SRCPATH=	github.com/mholt/caddy
GO_BUILD_PATTERN= ${GO_SRCPATH}/caddy

.include "../../net/go-net/buildlink3.mk"
.include "../../security/go-crypto/buildlink3.mk"

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
