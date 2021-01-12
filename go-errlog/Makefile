# $NetBSD$

DISTNAME=	errlog-20201130
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	errlog
GITHUB_TAG=	aef7af651c460f22471f5659fd91cf4f00036f67
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=snwfdhmp/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/snwfdhmp/errlog/
COMMENT=	Reduce debugging time while programming Go
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/snwfdhmp/${GITHUB_PROJECT}

.include "../../devel/go-afero/buildlink3.mk"
.include "../../devel/go-logrus/buildlink3.mk"
.include "../../wip/go-color/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
