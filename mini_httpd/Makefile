# $NetBSD: Makefile,v 1.4 2004/02/03 04:29:57 bjan2 Exp $

DISTNAME=	mini_httpd-1.19
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/mini_httpd/

MAINTAINER=	pkgsrc@bjan.freeshell.org
HOMEPAGE=	http://www.acme.com/software/mini_httpd/
COMMENT=	Small, forking webserver with IPv6 and SSL support

CONFLICTS=	apache*
USE_BUILDLINK2=	yes
MAKE_ENV+=	PKG_CFLAGS="${CFLAGS}"
LDFLAGS+=	-lssl -lcrypto -lcrypt -lutil

do-install:
	${INSTALL_PROGRAM} ${WORKSRC}/mini_httpd ${WORKSRC}/htpasswd ${BINDIR}
	${INSTALL_MAN} ${WORKSRC}/mini_httpd.8 ${PREFIX}/man/man8/
	${INSTALL_MAN} ${WORKSRC}/htpasswd.1 ${PREFIX}/man/man1/

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
