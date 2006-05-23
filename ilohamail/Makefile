# $NetBSD: Makefile,v 1.13 2006/05/23 23:37:38 ykomatsu Exp $
#

DISTNAME=	IlohaMail-0.8.14-rc2
PKGNAME=	ilohamail-0.8.14rc2
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ilohamail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ilohamail.org/
COMMENT=	Light weight yet full featured multilingual webmail

DEPENDS+=	ap-php>=4.3.0:../../www/ap-php

NO_BUILD=	yes

APACHE_USER?=	www
APACHE_GROUP?=	www

ILOHAMAIL_DIR=		${PREFIX}/share/ilohamail
ILOHAMAIL_CONF_DIR=	${ILOHAMAIL_DIR}/conf
ILOHAMAIL_CONF_FILES=	conf.inc conf.php custom_auth.inc db_conf.php \
			defaults.generic.inc defaults.inc login.inc \
			login_blurb.inc login_title.inc mysqlrc.inc \
			new_user.inc
ILOHAMAIL_CONF_PERMS=	${APACHE_USER} ${APACHE_GROUP} 0644
EGDIR=			${PREFIX}/share/examples/ilohamail
OWN_DIRS_PERMS+=	${ILOHAMAIL_CONF_DIR} ${APACHE_USER} ${APACHE_GROUP} \
			0755
.for file in ${ILOHAMAIL_CONF_FILES}
CONF_FILES_PERMS+=	${EGDIR}/conf/${file} \
			${ILOHAMAIL_CONF_DIR}/${file} \
			${ILOHAMAIL_CONF_PERMS}
.endfor

do-install:
	${INSTALL_DATA_DIR} ${ILOHAMAIL_DIR}
	cd ${WRKSRC}/IlohaMail && ${PAX} -r -w data include index.html lang \
		source ${ILOHAMAIL_DIR}
	cd ${WRKSRC}/IlohaMail && ${PAX} -r -w conf ${EGDIR}
	${CHOWN} -R ${APACHE_USER}:${APACHE_GROUP} ${ILOHAMAIL_DIR}

.include "../../mk/bsd.pkg.mk"
