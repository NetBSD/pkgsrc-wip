# $NetBSD: Makefile,v 1.4 2004/05/02 22:03:41 blef Exp $
#

DISTNAME=		gateway-1.2.1
CATEGORIES=		wip
MASTER_SITES=	http://www.kannel.org/download/1.2.1/

MAINTAINER=		adam@monkeybyte.org
HOMEPAGE=		http://www.kannel.org/download/1.2.1/
COMMENT=		Kannel WAP gateway

USE_BUILDLINK3=         yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=            yes
GNU_CONFIGURE=          yes

CONFIGURE_ARGS+=		--disable-ssl
CONFIGURE_ARGS+= 		--disable-docs

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
