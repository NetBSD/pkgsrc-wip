# $NetBSD: Makefile,v 1.3 2015/01/13 21:36:40 bsiegert Exp $
#

DISTNAME=		go-tools
CATEGORIES=		devel

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		http://golang.org/
COMMENT=		Tools for use with Go, including godoc
LICENSE=		modified-bsd

GO_SRCPATH=		golang.org/x/tools
GO_DIST_BASE=		${DISTNAME}

CHECKOUT_DATE=		2014-11-18
HG_REPOSITORIES=	${DISTNAME}
HG_REPO.${DISTNAME}=	https://code.google.com/p/go.tools

DEPENDS+=		go-net-*:../../wip/go-net
DEPENDS+=		goauth2-*:../../wip/goauth2
DEPENDS+=		google-api-go-client-*:../../wip/google-api-go-client

.include "../../lang/go/go-package.mk"

INSTALLATION_DIRS+=	${GOTOOLDIR}

post-install:
	mv ${DESTDIR}${PREFIX}/bin/cover ${DESTDIR}${GOTOOLDIR}
	mv ${DESTDIR}${PREFIX}/bin/vet ${DESTDIR}${GOTOOLDIR}

.include "../../wip/mk/hg-package.mk"
.include "../../mk/bsd.pkg.mk"
