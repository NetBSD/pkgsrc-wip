# $NetBSD$

VER=		0.0.5
GITHUB_PROJECT=	juniper-SNMPv3-crypt
GITHUB_TAG=	416b694
DISTNAME=	${GITHUB_PROJECT:S/-${VER}//}
CATEGORIES=	net
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${VER}
MASTER_SITES=	${MASTER_SITE_GITHUB:=zach-bray/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zach-bray/juniper-SNMPv3-crypt
COMMENT=	Juniper crypto operations
LICENSE=	mit

EGG_NAME=	${GITHUB_PROJECT:S/-//g}-${VER}
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT:S/-${VER}//}-416b694a24bef793d47ed6ec64f5649e5fd35c32

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
