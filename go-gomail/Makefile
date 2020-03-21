# $NetBSD$

PKGNAME=	go-gomail-2.0.0
PKGREVISION=	7
DISTNAME=	go-gomail
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=go-gomail/}
GITHUB_PROJECT=	gomail
GITHUB_TAG=	81ebce5c23dfd25c6c67194b37d3dd3f338c98b1

MAINTAINER=	iku.iwasa@gmail.com
HOMEPAGE=	https://github.com/go-gomail/gomail
COMMENT=	The best way to send emails in Go
LICENSE=	mit

EXTRACT_USING=	bsdtar

GO_SRCPATH=	gopkg.in/gomail.v2
GO_DIST_BASE=	${DISTNAME:S/go-//}-${GITHUB_TAG}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
