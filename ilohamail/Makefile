# $NetBSD: Makefile,v 1.10 2004/12/14 12:35:10 poppnk Exp $
#

DISTNAME=	IlohaMail-0.8.14-rc1
PKGNAME=	${DISTNAME:S/IlohaM/iloham/}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ilohamail/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ilohamail.org/
COMMENT=	Light weight yet full featured multilingual webmail

DEPENDS+=	ap{,2}-php>=4.3.0:../../www/ap-php

NO_BUILD=	yes

APACHE_DOCROOT=	${PREFIX}/share/httpd/htdocs
ILOHADIR=	${APACHE_DOCROOT}/IlohaMail
PKG_SYSCONFDIR=${ILOHADIR}/conf/

do-install:
	${INSTALL_DATA_DIR} ${ILOHADIR}/conf
	${INSTALL_DATA_DIR} ${ILOHADIR}/conf-orig
	@${CP} -rf ${ILOHADIR}/conf/ ${ILOHADIR}/conf-orig/
	@${CP} -r  ${WRKSRC}/IlohaMail/ ${ILOHADIR}
	@${CP} -rf ${ILOHADIR}/conf-orig/ ${ILOHADIR}/conf/
	@${CP} -rf ${WRKSRC}/IlohaMail/conf/ ${ILOHADIR}/conf-orig/
	${CHMOD} -R 700 ${ILOHADIR}
	${CHOWN} -R www:www ${ILOHADIR}

.include "../../mk/bsd.pkg.mk"
