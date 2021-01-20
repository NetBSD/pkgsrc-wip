# $NetBSD$

DISTNAME=	json-iterator-20200608
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	go
GITHUB_TAG=	a1ca0830781e007c66b225121d2cdb3a649421f6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=json-iterator/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jsoniter.com/migrate-from-go-std.html
COMMENT=	High-performance compatible drop-in replacement of encoding/json
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/json-iterator/${GITHUB_PROJECT}

USE_TOOLS+=	bash:run

REPLACE_BASH+=	test.sh

.include "../../wip/go-concurrent/buildlink3.mk"
.include "../../wip/go-reflect2/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
