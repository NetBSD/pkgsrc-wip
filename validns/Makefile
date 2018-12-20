# $NetBSD$

DISTNAME=	validns
PKGNAME=	validns-0.8
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=tobez/}
GITHUB_PROJECT=	validns
GITHUB_TAG=	f423245b9867359398f83e8a60fea167ad7694ca

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	DNS and DNSSEC zone file validator
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c
USE_TOOLS+=	gmake
WRKSRC=		${WRKDIR}/${DISTNAME}-${GITHUB_TAG}

.include "../../wip/judy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
