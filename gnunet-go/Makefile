# $NetBSD$

DISTNAME=		gnunet-go-0.1.40
MASTER_SITES=		${MASTER_SITE_GITHUB:=bfix/}
CATEGORIES=		net
GITHUB_TAG=		v${PKGVERSION_NOREV}
GITHUB_PROJECT=		gnunet-go

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/bfix/gnunet-go/
COMMENT=	GNUnet implementation in Go
LICENSE=	gnu-agpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME}/src/gnunet

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
