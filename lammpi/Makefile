# $NetBSD: Makefile,v 1.4 2004/07/02 19:42:35 thomasklausner Exp $
#

DISTNAME=		lam-7.0.2
CATEGORIES=		wip
MASTER_SITES=	http://www.lam-mpi.org/download/files/

MAINTAINER=	adam@monkeybyte.org
HOMEPAGE=	http://www.lam-mpi.org/download/files/
COMMENT=	Implementation of the Message Passing Interface (MPI) Standard

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
