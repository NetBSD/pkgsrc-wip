# $NetBSD: Makefile,v 1.1.1.1 2003/05/31 17:37:32 xtraeme Exp $
#

DISTNAME=	IlohaMail-0.7.11
PKGNAME=	${DISTNAME:S/IlohaM/iloham/}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ilohamail/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.ilohamail.org/
COMMENT=	Light weight yet full featured multilingual webmail

DEPENDS=	ap-php4-[0-9]*:../../www/ap-php4

NO_BUILD=	yes

APACHE_DOCROOT=	${PREFIX}/share/httpd/htdocs
ILOHADIR=	${APACHE_DOCROOT}/IlohaMail

do-install:
	@${CP} -r ${WRKSRC}/IlohaMail ${APACHE_DOCROOT}
	${INSTALL_DATA_DIR} ${ILOHADIR}/users
	${INSTALL_DATA_DIR} ${ILOHADIR}/sessions
	${INSTALL_DATA_DIR} ${ILOHADIR}/uploads
	${INSTALL_DATA_DIR} ${ILOHADIR}/cache
	${CHMOD} -R 700 ${ILOHADIR}
	${CHOWN} -R www:www ${ILOHADIR}

.include "../../mk/bsd.pkg.mk"
