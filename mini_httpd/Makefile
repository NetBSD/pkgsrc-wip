# $NetBSD: Makefile,v 1.3 2004/02/02 23:34:06 bjan2 Exp $

DISTNAME=	mini_httpd-1.19
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/mini_httpd/

MAINTAINER=	pkgsrc@bjan.freeshell.org
HOMEPAGE=	http://www.acme.com/software/mini_httpd/
COMMENT=	Small, forking webserver with IPv6 and SSL support

MAKE_ENV+=	PKG_CFLAGS="${CFLAGS}"
LDFLAGS+=	-lssl -lcrypto -lcrypt -lutil

post-build:
	strip ${WRKSRC}/mini_httpd ${WRKSRC}/htpasswd

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
