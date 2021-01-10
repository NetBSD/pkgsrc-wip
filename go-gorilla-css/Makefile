# $NetBSD$

DISTNAME=	gorilla-css-20190627
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	css
GITHUB_TAG=	4940b8d7810384b58c15dbf1103a148fdf0761f2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=gorilla/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/gorilla/css/
COMMENT=	CSS3 tokenizer
LICENSE=	2-clause-bsd

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/gorilla/${GITHUB_PROJECT}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
