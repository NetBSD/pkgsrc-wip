# $NetBSD: Makefile,v 1.2 2004/01/16 03:38:22 minskim Exp $
#

DISTNAME=		aget-0.4
CATEGORIES=		net
MASTER_SITES=		http://www.enderunix.org/aget/

MAINTAINER=	 	eeg@e3labs.ath.cx
HOMEPAGE=		http://www.enderunix.org/aget/
COMMENT=	 	Multithreaded HTTP download accelerator

USE_BUILDLINK2=		yes

PTHREAD_OPTS+=          require

.include "../../mk/pthread.buildlink2.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aget ${PREFIX}/bin/aget
.include "../../mk/bsd.pkg.mk"
