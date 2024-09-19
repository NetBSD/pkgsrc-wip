# $NetBSD$

GITHUB_PROJECT=	go-junit-report
GITHUB_TAG=	af01ea7f8024089b458d804d5cdf190f962a9a0c
#DISTNAME=	go-junit-report
DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}

PKGREVISION=	7
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=jstemmer/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ejstemmer/go-junit-report
COMMENT=	TODO: Short description of the package
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/jstemmer/go-junit-report/

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
