# $NetBSD$

DISTNAME=		lumberjack-2.0
PKGREVISION=		12
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=natefinch/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		https://gopkg.in/natefinch/lumberjack.v2
COMMENT=		Rolling logger for Go
LICENSE=		mit

GO_SRCPATH=		gopkg.in/natefinch/lumberjack.v2
GO_DIST_BASE=		${DISTNAME}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
