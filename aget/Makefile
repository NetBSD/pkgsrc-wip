# $NetBSD: Makefile,v 1.3 2004/01/22 20:50:16 rillig Exp $
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

.if ${OPSYS} == "SunOS"
post-configure:
	(cd ${WRKDIR}/${DISTNAME} && ${MV} Makefile.Solaris Makefile)
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aget ${PREFIX}/bin/aget
.include "../../mk/bsd.pkg.mk"
