# $NetBSD: Makefile,v 1.10 2012/10/01 21:57:33 asau Exp $
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

CONFIGURE_ARGS+=	--disable-ssl
CONFIGURE_ARGS+=	--disable-docs

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
