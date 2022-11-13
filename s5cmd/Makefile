# $NetBSD$

PKGVERSION=	2.0.0
DISTNAME=	s5cmd-v${PKGVERSION}
PKGNAME=	s5cmd-${PKGVERSION}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=peak/}
GITHUB_PROJECT=	s5cmd

MAINTAINER=	stix@stix.id.au
HOMEPAGE=	https://github.com/peak/s5cmd
COMMENT=	Ultra-fast tool for managing s3 compatible storage
LICENSE=	mit

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

DEPENDS+=	go>=1.17:../../lang/go

.include "go-modules.mk"
# .include "../../mk/bsd.prefs.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
