# $NetBSD: Makefile,v 1.1.1.1 2003/09/28 13:01:54 adrian_p Exp $

DISTNAME=	prelude-lml-0.8.4
CATEGORIES=	net www
MASTER_SITES=	http://www.prelude-ids.org/download/releases/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.prelude-ids.org/
COMMENT=	Prelude HIDS sensor

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
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
