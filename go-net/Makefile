# $NetBSD: Makefile,v 1.2 2014/11/20 10:53:47 bsiegert Exp $
#

DISTNAME=		go-net
CATEGORIES=		devel

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		http://golang.org/
COMMENT=		Supplementary network libraries for Go
LICENSE=		modified-bsd

GO_SRCPATH=		golang.org/x/net
GO_DIST_BASE=		${DISTNAME}

CHECKOUT_DATE=		2014-11-18
HG_REPOSITORIES=	${DISTNAME}
HG_REPO.${DISTNAME}=	https://code.google.com/p/go.net

DEPENDS+=		go-text-*:../../wip/go-text

.include "../../wip/go/go-package.mk"
.include "../../wip/mk/hg-package.mk"
.include "../../mk/bsd.pkg.mk"
