# $NetBSD: Makefile,v 1.5 2009/11/22 15:30:21 gschwarz Exp $

DISTNAME=	libeXosip2-3.3.0
CATEGORIES=	devel
MASTER_SITES=	http://download.savannah.nongnu.org/releases/exosip/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/exosip
COMMENT=	The Extended Open SIP library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_FEATURES+=		getopt_long

DEPENDS+=	libosip2>=3.2.0:../../devel/libosip
.include "../../devel/libosip/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
