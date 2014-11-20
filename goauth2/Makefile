# $NetBSD: Makefile,v 1.1 2014/11/20 10:58:46 bsiegert Exp $
#

DISTNAME=		goauth2
CATEGORIES=		devel

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		http://golang.org/
COMMENT=		OAuth 2 library for Go
LICENSE=		modified-bsd

GO_SRCPATH=		code.google.com/p/goauth2
GO_DIST_BASE=		${DISTNAME}

CHECKOUT_DATE=		2014-11-18
HG_REPOSITORIES=	${DISTNAME}
HG_REPO.${DISTNAME}=	https://${GO_SRCPATH}

#DEPENDS+=		go-text-*:../../wip/go-text

.include "../../wip/go/go-package.mk"
.include "../../wip/mk/hg-package.mk"
.include "../../mk/bsd.pkg.mk"
