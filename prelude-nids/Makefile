# $NetBSD: Makefile,v 1.6 2005/04/11 21:14:50 tvierling Exp $

DISTNAME=	prelude-nids-0.8.6
CATEGORIES=	net www
MASTER_SITES=	http://www.prelude-ids.org/download/releases/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.prelude-ids.org/
COMMENT=	Prelude NIDS sensor

GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_PKGINSTALL=		YES

PTHREAD_OPTS=		require

PKG_SYSCONFSUBDIR=	prelude-nids

CONF_FILES=		${WRKSRC}/prelude-nids.conf \
			${PKG_SYSCONFDIR}/prelude-nids.conf

CONFIGURE_ARGS+=	--enable-ipv6

.include "../../wip/libprelude/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
