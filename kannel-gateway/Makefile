# $NetBSD: Makefile,v 1.3 2004/01/25 02:23:28 grantbeattie Exp $
#

DISTNAME=		gateway-1.2.1
CATEGORIES=		wip
MASTER_SITES=	http://www.kannel.org/download/1.2.1/

MAINTAINER=		adam@monkeybyte.org
HOMEPAGE=		http://www.kannel.org/download/1.2.1/
COMMENT=		Kannel WAP gateway

USE_BUILDLINK2=         yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=            yes
GNU_CONFIGURE=          yes

CONFIGURE_ARGS+=		--disable-ssl
CONFIGURE_ARGS+= 		--disable-docs
.include "../../mk/pthread.buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
