# $NetBSD: Makefile,v 1.2 2005/12/06 07:39:34 lkundrak Exp $

DISTNAME=	mod_auth_pam-2.0-1.1.1
PKGNAME=	ap2-auth-pam-1.1.1
CATEGORIES=	www
MASTER_SITES=	http://pam.sourceforge.net/mod_auth_pam/dist/
# Even though it is on sourceforge, it is in web pages repository!

MAINTAINER=	lkundrak@elvraba.edu.sk
HOMEPAGE=	http://pam.sourceforge.net/mod_auth_pam/
COMMENT=	Apache2 module for PAM authentification

APACHE_MODULE_NAME=	mod_auth_pam
USE_TOOLS+=		gmake

EGDIR=		${PREFIX}/share/examples/mod_auth_pam
HTMLDIR=	${PREFIX}/share/doc/html/mod_auth_pam

post-extract:
	${MV} ${WRKDIR}/mod_auth_pam ${WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/httpd ${EGDIR}/httpd.pam
	${INSTALL_DATA} ${WRKSRC}/doc/configure.html ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/faq.html ${HTMLDIR}

.include "../../www/apache2/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
