# $NetBSD$

DISTNAME=	nltk_data
PKGNAME=	${DISTNAME}-20171223
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=nltk/}
GITHUB_TAG= 	f3dc1f388b08aa310933dbddf21e12b9fc6b50f1

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.nltk.org/nltk_data/
COMMENT=	Data distribution for NLTK

NO_BUILD=	yes
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	share/${PKGBASE}

do-install:
	cd ${WRKSRC}/packages && pax -rw . ${DESTDIR}${PREFIX}/share/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
