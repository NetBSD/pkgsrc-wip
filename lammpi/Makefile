# $NetBSD: Makefile,v 1.7 2005/05/24 10:30:30 rillig Exp $
#

DISTNAME=	lam-7.0.2
CATEGORIES=	net
MASTER_SITES=	http://www.lam-mpi.org/download/files/

MAINTAINER=	adam@monkeybyte.org
HOMEPAGE=	http://www.lam-mpi.org/download/files/
COMMENT=	Implementation of the Message Passing Interface (MPI) Standard

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
