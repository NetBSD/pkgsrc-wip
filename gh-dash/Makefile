# $NetBSD: Makefile,v 1.87 2024/11/25 19:18:07 bsiegert Exp $

DISTNAME=	gh-dash-4.9.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=dlvhdr/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dlvhdr/gh-dash
COMMENT=	GitHub CLI extension that provides dashboard for PR and issues
LICENSE=	mit

DEPENDS+=	gh-[0-9]*:../../net/gh

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
