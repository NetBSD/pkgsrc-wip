# $NetBSD: Makefile,v 1.1.1.1 2004/10/14 22:45:20 johnrshannon Exp $
#

DISTNAME=		librfuncs-1.0
CATEGORIES=		devel
MASTER_SITES=		http://www.johnrshannon.com/NetBSD/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://www.johnrshannon.com/NetBSD/
COMMENT=		Provides missing POSIX *_r functions

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
PTHREAD_OPTS+=		require

TEST_TARGET=		check

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
