# $NetBSD: Makefile,v 1.1.1.1 2003/09/28 13:02:17 adrian_p Exp $

DISTNAME=	prelude-nids-0.8.3
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
