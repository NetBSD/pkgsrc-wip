# $NetBSD$

DISTNAME=	go-rest-2.4.1
PKGREVISION=	12
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_GITHUB:=sendgrid/}
GITHUB_PROJECT=	rest
GITHUB_TAG=	v${PKGVERSION_NOREV}

HOMEPAGE=	https://github.com/sendgrid/rest
COMMENT=	SendGrid's Golang HTTP Client for calling APIs
LICENSE=	mit

EXTRACT_USING=	bsdtar

GO_SRCPATH=	github.com/sendgrid/rest/
GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
