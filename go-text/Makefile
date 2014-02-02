# $NetBSD: Makefile,v 1.3 2014/02/02 14:01:59 bsiegert Exp $
#

DISTNAME=		go.text
CATEGORIES=		devel

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		http://golang.org/
COMMENT=		Supplementary text processing libraries for Go
LICENSE=		modified-bsd

GO_SRCPATH=		code.google.com/p/go.text
WRKSRC=			${WRKDIR}/src/${GO_SRCPATH}

CHECKOUT_DATE=		2014-01-16
HG_REPOSITORIES=	${DISTNAME}
HG_REPO.${DISTNAME}=	https://${GO_SRCPATH}

.include "../../wip/go/go-package.mk"
.include "../../wip/mk/hg-package.mk"
.include "../../mk/bsd.pkg.mk"
