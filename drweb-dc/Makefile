# $NetBSD: Makefile,v 1.3 2004/03/12 00:21:06 minskim Exp $

DRW_CLIENT_NAME=	dc

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Command line client for DrWeb Daemon antivirus

do-install:
			${INSTALL_PROGRAM} ${WRKSRC}/drwebdc ${PREFIX}/sbin

.include "../../wip/drweb-clients-shared/Makefile.common"
.include "../../mk/bsd.pkg.mk"
