# $NetBSD: Makefile,v 1.4 2003/10/20 11:06:46 adrian_p Exp $
#

DISTNAME=	mod_security-1.7
PKGNAME=	ap-security-1.7
CATEGORIES=	www security
MASTER_SITES=	http://www.modsecurity.org/download/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://www.modsecurity.org/
COMMENT=	Intrusion detection and prevention engine for web applications

USE_BUILDLINK2=		YES
APACHE_MODULE=		YES
NO_BUILD=		YES

#APACHE_MODULE_NAME=	${DISTNAME:C|-.*||}.so
#APACHE_MODULE_SRC=      ${DISTNAME:C|-.*||}.c
APACHE_MODULE_SRCDIR=	${WRKSRC}/apache1

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ap-security
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ap-security

	${INSTALL_DATA} ${WRKSRC}/httpd.conf.example-full \
		${PREFIX}/share/examples/ap-security

	${INSTALL_DATA} ${WRKSRC}/httpd.conf.example-minimal \
		${PREFIX}/share/examples/ap-security

	${INSTALL_DATA} ${WRKSRC}/modsecurity-manual-v1.6.pdf \
		${PREFIX}/share/doc/ap-security

	${INSTALL_DATA} ${WRKSRC}/LICENSE \
		${PREFIX}/share/doc/ap-security

.include "../../mk/apache.mk"

.include "../../mk/bsd.pkg.mk"
