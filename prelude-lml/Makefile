# $NetBSD: Makefile,v 1.3 2004/01/25 02:33:17 grantbeattie Exp $

DISTNAME=	prelude-lml-0.8.5
CATEGORIES=	net www
MASTER_SITES=	http://www.prelude-ids.org/download/releases/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.prelude-ids.org/
COMMENT=	Prelude HIDS sensor

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make
USE_PKGINSTALL=		YES

PKG_SYSCONFSUBDIR=	prelude-lml

CONF_FILES=	${WRKSRC}/prelude-lml.conf \
		${PKG_SYSCONFDIR}/prelude-lml.conf
CONF_FILES+=	${WRKSRC}/plugins.rules \
		${PKG_SYSCONFDIR}/plugins.rules

PTHREAD_OPTS=		require

.include "../../wip/libprelude/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../devel/pcre/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
