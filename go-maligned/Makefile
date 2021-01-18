# $NetBSD$

DISTNAME=	go-maligned-20180606
GITHUB_PROJECT=	maligned
GITHUB_TAG=	b1d8939
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=golangci/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/golangci/maligned
COMMENT=	Tool to detect Go structs that would take less memory
LICENSE=	2-clause-bsd

GO_DIST_BASE=   ${GITHUB_PROJECT}-${GITHUB_TAG}*
GO_SRCPATH=     https://github.com/golangci/maligned

.include "../../devel/go-tools/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
