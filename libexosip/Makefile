# $NetBSD: Makefile,v 1.12 2013/07/14 15:54:36 othyro Exp $

DISTNAME=	libeXosip2-4.0.0
CATEGORIES=	devel net
MASTER_SITES=	http://download.savannah.nongnu.org/releases/exosip/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/exosip
COMMENT=	The Extended Open SIP library
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_FEATURES+=		getopt_long
USE_TOOLS+=	pkg-config

LIBS.SunOS+=		-lsocket -lnsl

.include "../../devel/libosip/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
