# $NetBSD: Makefile,v 1.1 2020/12/31 14:34:12 jihbed Exp $

DISTNAME=	concurrent-20180306
PKGNAME=	go-${DISTNAME}
PKGVERSION=	1
GITHUB_PROJECT=	concurrent
GITHUB_TAG=	bacd9c7ef1dd9b15be4a9909b8ac7a4e313eec94
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=modern-go/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/modern-go/concurrent/
COMMENT=	Golang concurrency utilities
LICENSE=	apache-2.0

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/modern-go/${GITHUB_PROJECT}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
