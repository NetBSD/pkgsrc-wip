# $NetBSD: Makefile,v 1.1.1.1 2005/11/14 23:22:00 poppnk Exp $
#

DISTNAME=		nstx-1.1-beta6
CATEGORIES=		wip net
MASTER_SITES=		http://nstx.dereference.de/nstx/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://nstx.dereference.de/nstx/
COMMENT=		Nameserver Transfer Protocol

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nstxcd ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nstxd ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nstx
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nstx/

.include "../../mk/bsd.pkg.mk"
