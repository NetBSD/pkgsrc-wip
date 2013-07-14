# $NetBSD: Makefile,v 1.13 2013/07/14 19:04:59 othyro Exp $

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

.include "options.mk"

LIBS.SunOS+=		-lsocket -lnsl

.include "../../net/libcares/buildlink3.mk"
.include "../../devel/libosip/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
