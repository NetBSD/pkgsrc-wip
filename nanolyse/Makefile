# $NetBSD$

GITHUB_PROJECT=	nanolyse
GITHUB_TAG=	a3de1e9
DISTNAME=	NanoLyse-1.2.0.20200915
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_GITHUB:=wdecoster/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wdecoster/nanolyse
COMMENT=	Removing reads mapping to the lambda genome
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-biopython>=1.74:../../biology/py-biopython
DEPENDS+=	${PYPKGPREFIX}-mappy>=2.18:../../wip/py-mappy

WRKSRC=		${WRKDIR}/nanolyse-a3de1e9c81aeddf15ef985486ca80b6876674948
USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:C/\.[[:digit:]]+$$//}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
