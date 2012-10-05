# $NetBSD: Makefile,v 1.5 2012/10/05 13:52:03 asau Exp $

POUND_VERSION=	2.4.5
PKGNAME=	pound-${POUND_VERSION}
DISTNAME=	Pound-${POUND_VERSION}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.apsis.ch/pound/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tonnerre@bsdprojects.net
HOMEPAGE=	http://www.apsis.ch/pound/
COMMENT=	Reverse-proxy and load-balancer

PKG_DESTDIR_SUPPORT=	none

HAS_CONFIGURE=	yes
USE_BUILTIN.openssl=	no

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

CONFIGURE_ARGS+= --with-ssl=${SSLBASE:Q}
CONFIGURE_ARGS+= --prefix=${PREFIX:Q}
CONFIGURE_ARGS+= --mandir=${PREFIX:Q}/${PKGMANDIR:Q}

.include "../../mk/bsd.pkg.mk"
