# $NetBSD: Makefile,v 1.2 2015/03/12 21:11:14 tnn2 Exp $
#

DISTNAME=		go-dotenv-${GITHUB_TAG}
PKGNAME=		go-dotenv-20180121
PKGREVISION=		12
GITHUB_PROJECT=		go-dotenv
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=direnv/}
GITHUB_TAG=		4738ec4

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/direnv/go-dotenv/
COMMENT=		Go parsing library for the dotenv format
LICENSE=		mit

GO_SRCPATH=		github.com/direnv/go-dotenv
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
