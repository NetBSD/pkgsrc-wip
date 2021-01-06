# $NetBSD$

DISTNAME=	go-uuid-1.1.3
GITHUB_PROJECT=	uuid
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/google/uuid/
COMMENT=	Go package for UUIDs based on RFC 4122 and DCE 1.1
LICENSE=	2-clause-bsd

GO_SRCPATH=	github.com/google/uuid
GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}

.include "../../devel/go-sync/buildlink3.mk"
.include "../../net/go-net/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
