# $NetBSD: Makefile,v 1.6 2004/05/12 21:44:10 poppnk Exp $
#

DISTNAME=	IlohaMail-0.8.12
PKGNAME=	${DISTNAME:S/IlohaM/iloham/}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ilohamail/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ilohamail.org/
COMMENT=	Light weight yet full featured multilingual webmail

.include "../../mk/bsd.prefs.mk"

.if defined(ILOHAMAIL_USE_PHP5) && ${ILOHAMAIL_USE_PHP5} == YES
DEPENDS+=	{ap-php-5.[0-9]*,ap2-php-5.[0-9]*}:../../wip/ap-php5
.else
DEPENDS+=	{ap-php-4.[0-9]*,ap2-php-4.[0-9]*}:../../www/ap-php4
.endif

NO_BUILD=	yes

APACHE_DOCROOT=	${PREFIX}/share/httpd/htdocs
ILOHADIR=	${APACHE_DOCROOT}/IlohaMail

do-install:
	@${CP} -r ${WRKSRC}/IlohaMail ${APACHE_DOCROOT}
	${CHMOD} -R 700 ${ILOHADIR}
	${CHOWN} -R www:www ${ILOHADIR}

.include "../../mk/bsd.pkg.mk"
