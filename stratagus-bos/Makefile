# $NetBSD: Makefile,v 1.2 2004/06/01 23:50:50 xtraeme Exp $
#

DISTNAME=	bos_1_0
PKGNAME=	stratagus-bos-1.0
CATEGORIES=	games
MASTER_SITES=	http://www.montefiore.ulg.ac.be/%7Efrancois/personal/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.nongnu.org/stratagus-bos/
COMMENT=	Battle of Survival data for stratagus

DEPENDS=	stratagus-2.0:../../wip/stratagus

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/data.bos

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/stratagus/bos
	cd ${WRKSRC} && ${PAX} -rwppm . ${PREFIX}/share/stratagus/bos/

.include "../../mk/bsd.pkg.mk"
