# $NetBSD: Makefile,v 1.1.1.1 2004/06/01 22:46:51 poppnk Exp $
#

DISTNAME=		bos_1_0
PKGNAME=		stratagus-bos-1.0
CATEGORIES=		wip
MASTER_SITES=		http://www.montefiore.ulg.ac.be/%7Efrancois/personal/
EXTRACT_SUFX=		.tgz
WRKSRC=		${WRKDIR}/data.bos

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.nongnu.org/stratagus-bos/
COMMENT=		Battle of Survival data for stratagus

DEPENDS=		stratagus-2.0:../../wip/stratagus

do-build:

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/stratagus/bos
	${CP} -rf ${WRKSRC}/* ${PREFIX}/share/stratagus/bos/

.include "../../mk/bsd.pkg.mk"
