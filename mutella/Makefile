# $NetBSD: Makefile,v 1.2 2003/05/20 18:43:43 xtraeme Exp $
#

DISTNAME=	mutella-0.4.3
CATEGORIES=	net www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mutella/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://mutella.sourceforge.net
COMMENT=	Console mode Gnutella client with optional http interface

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
HAS_CONFIGURE=		yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

PTHREAD_OPTS+=		require

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
