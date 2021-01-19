# $NetBSD$

DISTNAME=	go-ksuid-1.0.3
GITHUB_PROJECT=	ksuid
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=segmentio/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://segment.com/blog/a-brief-history-of-the-uuid/
COMMENT=	K-Sortable Globally Unique IDs
LICENSE=	mit

GO_DIST_BASE=   ${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=     github.com/segmentio/ksuid

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
