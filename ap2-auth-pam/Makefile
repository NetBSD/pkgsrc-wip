# $NetBSD: Makefile,v 1.9 2012/09/24 16:56:36 asau Exp $

DISTNAME=	mod_auth_pam-2.0-1.1.1
PKGNAME=	ap2-auth-pam-1.1.1
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://pam.sourceforge.net/mod_auth_pam/dist/
# Even though it is on sourceforge, it is in web pages repository!

MAINTAINER=	lkundrak@skosi.org
HOMEPAGE=	http://pam.sourceforge.net/mod_auth_pam/
COMMENT=	Apache2 module for PAM authentification

PKG_DESTDIR_SUPPORT=	none

APACHE_MODULE_NAME=	mod_auth_pam
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

EGDIR=		${PREFIX}/share/examples/mod_auth_pam
HTMLDIR=	${PREFIX}/share/doc/html/mod_auth_pam

post-extract:
	${MV} ${WRKDIR}/${APACHE_MODULE_NAME} ${WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/httpd ${EGDIR}/httpd.pam
	${INSTALL_DATA} ${WRKSRC}/doc/configure.html ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/faq.html ${HTMLDIR}

.include "../../www/apache2/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
