# $NetBSD$

GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}
DISTNAME=	acme-dns-1.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=joohoi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/joohoi/acme-dns/
COMMENT=	Simplified DNS server to automate ACME DNS challenges
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LANGUAGES=	c

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
