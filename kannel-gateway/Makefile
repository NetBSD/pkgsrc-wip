# $NetBSD: Makefile,v 1.5 2004/07/18 15:26:00 ppostma Exp $
#

DISTNAME=		gateway-1.2.1
CATEGORIES=		net
MASTER_SITES=		http://www.kannel.org/download/1.2.1/

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
