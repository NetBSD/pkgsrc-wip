# $NetBSD: Makefile,v 1.4 2004/02/07 14:15:41 adrian_p Exp $

DISTNAME=	libprelude-0.8.10
CATEGORIES=	net www
MASTER_SITES=	http://www.prelude-ids.org/download/releases/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.prelude-ids.org/
COMMENT=	Hybrid IDS

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make
USE_PKGINSTALL=         YES

PTHREAD_OPTS=		require

PKG_SYSCONFSUBDIR=	prelude-sensors

CONF_FILES=	${WRKSRC}/sensors-default.conf \
		${PKG_SYSCONFDIR}/sensors-default.conf

CONFIGURE_ARGS+=	--enable-openssl

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
