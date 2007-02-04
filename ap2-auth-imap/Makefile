# $Id: Makefile,v 1.4 2007/02/04 01:04:22 christian_gall Exp $
# $NetBSD: Makefile,v 1.4 2007/02/04 01:04:22 christian_gall Exp $

DISTNAME=	mod_auth_imap2-2.2.0
PKGNAME=	ap2-auth-imap-2.2.0
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
