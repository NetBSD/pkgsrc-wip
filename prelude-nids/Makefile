# $NetBSD: Makefile,v 1.2 2003/10/20 08:28:49 adrian_p Exp $

DISTNAME=	prelude-nids-0.8.4
CATEGORIES=	net www
MASTER_SITES=	http://www.prelude-ids.org/download/releases/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.prelude-ids.org/
COMMENT=	Prelude NIDS sensor

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_PKGINSTALL=		YES

PTHREAD_OPTS=		require

PKG_SYSCONFSUBDIR=	prelude-nids

CONF_FILES=		${WRKSRC}/prelude-nids.conf \
			${PKG_SYSCONFDIR}/prelude-nids.conf

CONFIGURE_ARGS+=	--enable-ipv6

.include "../../wip/libprelude/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
