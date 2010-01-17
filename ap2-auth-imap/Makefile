# $Id: Makefile,v 1.7 2010/01/17 12:03:23 thomasklausner Exp $
# $NetBSD: Makefile,v 1.7 2010/01/17 12:03:23 thomasklausner Exp $

DISTNAME=	mod_auth_imap2-2.2.0
PKGNAME=	ap2-auth-imap-2.2.0
PKGREVISION=	3
CATEGORIES=	www mail
MASTER_SITES=	http://ben.brillat.net/files/projects/mod_auth_imap2/

MAINTAINER=	cg@cgall.de
HOMEPAGE=	http://ben.brillat.net/projects/mod_auth_imap/
COMMENT=	Module to allow apache2 authentication against an IMAP server

APACHE_MODULE=		YES
APACHE_MODULE_NAME=	auth_imap_module

BUILDLINK_API_DEPENDS.apache+=	apache>=2.0.47

do-build:
	 cd ${WRKSRC} && \
	 	${APXS} -c -n ${APACHE_MODULE_NAME} mod_auth_imap.c

do-install:
	(cd ${WRKSRC} && ${APXS} -n ${APACHE_MODULE_NAME} -i mod_auth_imap.la && )

post-install:
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/examples/ap2-auth-imap
	${INSTALL_DATA} ${WRKSRC:Q}/examples/htaccess-example ${PREFIX:Q}/share/examples/ap2-auth-imap
	${INSTALL_DATA} ${WRKSRC:Q}/examples/httpd.conf-append-example ${PREFIX:Q}/share/examples/ap2-auth-imap

.include "../../www/apache2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
