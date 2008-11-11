# $NetBSD: Makefile,v 1.3 2008/11/11 22:07:39 gschwarz Exp $

DISTNAME=	libeXosip2-3.2.0
CATEGORIES=	devel
MASTER_SITES=	http://download.savannah.nongnu.org/releases/exosip/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/exosip
COMMENT=	The Extended Open SIP library

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

DEPENDS+=	libosip2>=3.2.0:../../devel/libosip
.include "../../devel/libosip/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
