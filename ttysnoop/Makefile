# $NetBSD: Makefile,v 1.3 2005/11/02 02:35:31 poppnk Exp $
#

# TODO : wrong name
DISTNAME=		ttysnoop-0.12d.k26
CATEGORIES=		wip sysutils
MASTER_SITES=		http://grad.icmc.usp.br/~duker/ttysnoop/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://grad.icmc.usp.br/~duker/ttysnoop/
COMMENT=		Snoop TTYs on Linux for kernels 2.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttysnoop ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ttysnoops ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/ttysnoop.8 ${PREFIX}/man/man8/

.include "../../mk/bsd.pkg.mk"
