# $NetBSD: Makefile,v 1.9 2011/12/19 13:05:35 gschwarz Exp $

DISTNAME=	libeXosip2-3.6.0
CATEGORIES=	devel
MASTER_SITES=	http://download.savannah.nongnu.org/releases/exosip/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/exosip
COMMENT=	The Extended Open SIP library
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_FEATURES+=		getopt_long

LIBS.SunOS+=		-lsocket -lnsl

.include "../../devel/libosip/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
