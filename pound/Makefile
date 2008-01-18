# $NetBSD: Makefile,v 1.2 2008/01/18 04:30:16 tnn2 Exp $

POUND_VERSION=	2.4c
PKGNAME=	pound-${POUND_VERSION}
DISTNAME=	Pound-${POUND_VERSION}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.apsis.ch/pound/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tonnerre@bsdprojects.net
HOMEPAGE=	http://www.apsis.ch/pound/
COMMENT=	Reverse-proxy and load-balancer

HAS_CONFIGURE=	yes
USE_BUILTIN.openssl=	no

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

CONFIGURE_ARGS+= --with-ssl=${SSLBASE:Q}
CONFIGURE_ARGS+= --prefix=${PREFIX:Q}
CONFIGURE_ARGS+= --mandir=${PREFIX:Q}/${PKGMANDIR:Q}

.include "../../mk/bsd.pkg.mk"
