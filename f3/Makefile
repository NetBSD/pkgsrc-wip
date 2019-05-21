# $NetBSD$

GITHUB_PROJECT=	f3
DISTNAME=	v7.1
PKGNAME=	${GITHUB_PROJECT}-7.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=AltraMayor/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	tpaul@NetBSD.org
HOMEPAGE=	http://oss.digirati.com.br/f3/
COMMENT=	Tests capacity and performance of flash media
LICENSE=	gnu-gpl-v3

WRKSRC=	${WRKDIR}/f3-7.1

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake

.include "../../devel/argp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
