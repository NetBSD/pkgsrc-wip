# $NetBSD: Makefile,v 1.1.1.1 2004/01/08 00:51:10 bjan2 Exp $

DISTNAME=	mini_httpd-1.19
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/mini_httpd/

MAINTAINER=	bjan+pkgsrc@bjan.freeshell.org
HOMEPAGE=	http://www.acme.com/software/mini_httpd/
COMMENT=	Small, forking webserver with IPv6 and SSL support

.include "../../security/openssl/buildlink2.mk"

MAKE_ENV+=	PKG_CFLAGS="${CFLAGS}"
LDFLAGS+=	-lssl -lcrypto

post-build:
	strip ${WRKSRC}/mini_httpd ${WRKSRC}/htpasswd

.include "../../mk/bsd.pkg.mk"
