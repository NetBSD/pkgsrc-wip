# $NetBSD: Makefile,v 1.3 2003/10/16 15:16:44 adrian_p Exp $

DISTNAME=	socat-1.3.2.1
WRKSRC=         ${WRKDIR}/socat-1.3
CATEGORIES=	net www
MASTER_SITES=	http://www.dest-unreach.org/socat/download/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.dest-unreach.org/socat/
COMMENT=	"netcat++" (extended design, new implementation)

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES

CONFIGURE_ARGS+=	--disable-libwrap
CONFIGURE_ARGS+=	--disable-readline

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
