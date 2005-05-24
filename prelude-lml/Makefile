# $NetBSD: Makefile,v 1.7 2005/05/24 10:31:20 rillig Exp $

DISTNAME=	prelude-lml-0.8.6
CATEGORIES=	net www
MASTER_SITES=	http://www.prelude-ids.org/download/releases/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.prelude-ids.org/
COMMENT=	Prelude HIDS sensor

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake
USE_PKGINSTALL=		YES

PKG_SYSCONFSUBDIR=	prelude-lml

CONF_FILES=	${WRKSRC}/prelude-lml.conf \
		${PKG_SYSCONFDIR}/prelude-lml.conf
CONF_FILES+=	${WRKSRC}/plugins.rules \
		${PKG_SYSCONFDIR}/plugins.rules

PTHREAD_OPTS=		require

.include "../../devel/pcre/buildlink3.mk"
.include "../../wip/libprelude/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
