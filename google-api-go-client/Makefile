# $NetBSD: Makefile,v 1.1 2014/11/20 10:58:46 bsiegert Exp $
#

DISTNAME=		google-api-go-client
CATEGORIES=		devel

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		http://golang.org/
COMMENT=		Go client library for various Google APIs
LICENSE=		modified-bsd

GO_SRCPATH=		code.google.com/p/google-api-go-client
GO_DIST_BASE=		${DISTNAME}

CHECKOUT_DATE=		2014-11-18
HG_REPOSITORIES=	${DISTNAME}
HG_REPO.${DISTNAME}=	https://${GO_SRCPATH}

DEPENDS+=		goauth2-*:../../wip/goauth2

.include "../../wip/go/go-package.mk"
.include "../../wip/mk/hg-package.mk"
.include "../../mk/bsd.pkg.mk"
