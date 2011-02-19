# $NetBSD: Makefile,v 1.8 2011/02/19 17:14:58 gschwarz Exp $

DISTNAME=	libeXosip2-3.5.0
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
CPPFLAGS.Darwin+=	-DBIND_8_COMPAT

.include "../../devel/libosip/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
