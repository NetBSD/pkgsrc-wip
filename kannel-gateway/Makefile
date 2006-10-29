# $NetBSD: Makefile,v 1.9 2006/10/29 08:32:45 shattered Exp $
#

DISTNAME=		gateway-1.2.1
CATEGORIES=		net
MASTER_SITES=		http://www.kannel.org/download/1.2.1/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.kannel.org/download/1.2.1/
COMMENT=		Kannel WAP gateway

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=		--disable-ssl
CONFIGURE_ARGS+=	--disable-docs

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
