# $NetBSD: Makefile,v 1.1.1.1 2003/09/13 13:00:25 bubuchka Exp $

DRW_CLIENT_NAME=	dc

MAINTAINER=		mishka@terabyte.com.ua
COMMENT=		Command line client for DrWeb Daemon antivirus

do-install:
			${INSTALL_PROGRAM} ${WRKSRC}/drwebdc ${PREFIX}/sbin

.include "../../wip/drweb-clients-shared/Makefile.common"
.include "../../mk/bsd.pkg.mk"
