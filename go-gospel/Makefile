# $NetBSD$

DISTNAME=	go-gospel-0.0.20190922
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=bfix/}
GITHUB_TAG=	6fcd6d4
GITHUB_PROJECT=	gospel

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://github.com/bfix/gospel/
COMMENT=	GO SPEcial Library
LICENSE=	gnu-gpl-v3

GO_SRCPATH=	github.com/bfix/gospel
GO_DIST_BASE=	gospel-${GITHUB_TAG}*

.include "../../security/go-crypto/buildlink3.mk"
.include "../../textproc/go-text/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
