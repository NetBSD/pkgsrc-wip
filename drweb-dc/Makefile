# $NetBSD: Makefile,v 1.2 2004/02/25 16:10:16 bubuchka Exp $

DRW_CLIENT_NAME=	dc

MAINTAINER=		tech-pkg@netbsd.org
COMMENT=		Command line client for DrWeb Daemon antivirus

do-install:
			${INSTALL_PROGRAM} ${WRKSRC}/drwebdc ${PREFIX}/sbin

.include "../../wip/drweb-clients-shared/Makefile.common"
.include "../../mk/bsd.pkg.mk"
