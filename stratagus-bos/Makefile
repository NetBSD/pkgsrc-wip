# $NetBSD: Makefile,v 1.3 2004/06/02 10:49:49 xtraeme Exp $
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
SHAREDIR=	${PREFIX}/share/stratagus/bos

do-install:
	${INSTALL_DATA_DIR} ${SHAREDIR}
	cd ${WRKSRC} && ${PAX} -rwppm . ${SHAREDIR}
	@(								\
	${ECHO_MSG} "#!/bin/sh";					\
	${ECHO_MSG} "exec ${PREFIX}/bin/stratagus -d ${SHAREDIR}"	\
	) >> ${WRKSRC}/stratagus-bos.sh
	${INSTALL_SCRIPT} ${WRKSRC}/stratagus-bos.sh			\
		${PREFIX}/bin/stratagus-bos

.include "../../mk/bsd.pkg.mk"
