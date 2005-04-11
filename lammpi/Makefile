# $NetBSD: Makefile,v 1.6 2005/04/11 21:13:39 tvierling Exp $
#

DISTNAME=	lam-7.0.2
CATEGORIES=	net
MASTER_SITES=	http://www.lam-mpi.org/download/files/

MAINTAINER=	adam@monkeybyte.org
HOMEPAGE=	http://www.lam-mpi.org/download/files/
COMMENT=	Implementation of the Message Passing Interface (MPI) Standard

GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
