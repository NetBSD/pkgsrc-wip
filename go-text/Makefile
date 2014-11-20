# $NetBSD: Makefile,v 1.5 2014/11/20 10:53:47 bsiegert Exp $
#

DISTNAME=		go-text
CATEGORIES=		devel

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		http://golang.org/
COMMENT=		Supplementary text processing libraries for Go
LICENSE=		modified-bsd

GO_SRCPATH=		golang.org/x/text
GO_DIST_BASE=		${DISTNAME}

CHECKOUT_DATE=		2014-11-18
HG_REPOSITORIES=	${DISTNAME}
HG_REPO.${DISTNAME}=	https://code.google.com/p/go.text

.include "../../wip/go/go-package.mk"
.include "../../wip/mk/hg-package.mk"
.include "../../mk/bsd.pkg.mk"
