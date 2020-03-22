# $NetBSD$

DISTNAME=	statzone-1.0.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=fcambus/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://github.com/fcambus/statzone
COMMENT=	DNS zone file analyzer targeted at TLD zones
LICENSE=	2-clause-bsd

USE_CMAKE=	yes

.include "../../devel/uthash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
