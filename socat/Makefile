# $NetBSD: Makefile,v 1.6 2004/02/14 15:05:54 minskim Exp $

DISTNAME=	socat-1.3.2.2
WRKSRC=         ${WRKDIR}/socat-1.3
CATEGORIES=	net www
MASTER_SITES=	http://www.dest-unreach.org/socat/download/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.dest-unreach.org/socat/
COMMENT=	"netcat++" (extended design, new implementation)

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_GNU_READLINE=	YES

CONFIGURE_ARGS+=	--disable-libwrap
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}

pre-install:
	${CP} ${WRKSRC}/socat.1 ${WRKSRC}/socat.1.orig
	${SED} -e 's#@PREFIX@#${PREFIX}#g' < ${WRKSRC}/socat.1.orig \
		> ${WRKSRC}/socat.1

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
