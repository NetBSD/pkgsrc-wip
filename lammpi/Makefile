# $NetBSD: Makefile,v 1.5 2004/07/18 15:25:59 ppostma Exp $
#

DISTNAME=	lam-7.0.2
CATEGORIES=	net
MASTER_SITES=	http://www.lam-mpi.org/download/files/

MAINTAINER=	adam@monkeybyte.org
HOMEPAGE=	http://www.lam-mpi.org/download/files/
COMMENT=	Implementation of the Message Passing Interface (MPI) Standard

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
