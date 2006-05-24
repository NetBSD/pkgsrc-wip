# $NetBSD: Makefile,v 1.14 2006/05/24 00:24:47 ykomatsu Exp $
#

DISTNAME=	IlohaMail-0.8.14-rc3
PKGNAME=	ilohamail-0.8.14rc3
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
ILOHAMAIL_DOC_DIR=	${PREFIX}/share/doc/ilohamail
ILOHAMAIL_CONF_FILES=	conf.inc conf.php custom_auth.php db_conf.php \
			defaults.generic.inc defaults.inc login.php \
			login_blurb.inc login_title.inc new_user.php
ILOHAMAIL_CONF_PERMS=	${APACHE_USER} ${APACHE_GROUP} 0644
EGDIR=			${PREFIX}/share/examples/ilohamail
OWN_DIRS_PERMS+=	${ILOHAMAIL_CONF_DIR} ${APACHE_USER} ${APACHE_GROUP} \
			0755
.for file in ${ILOHAMAIL_CONF_FILES}
CONF_FILES_PERMS+=	${EGDIR}/conf/${file} \
			${ILOHAMAIL_CONF_DIR}/${file} \
			${ILOHAMAIL_CONF_PERMS}
.endfor

pre-install:
	${FIND} ${WRKSRC} -name "*.orig" -print -type f | ${XARGS} ${RM} -f

do-install:
	${INSTALL_DATA_DIR} ${ILOHAMAIL_DIR}
	${INSTALL_DATA_DIR} ${ILOHAMAIL_DOC_DIR}
	cd ${WRKSRC}/IlohaMail && ${PAX} -r -w data include index.html lang \
		source ${ILOHAMAIL_DIR}
	cd ${WRKSRC}/IlohaMail && ${PAX} -r -w conf ${EGDIR}
	cd ${WRKSRC} && ${PAX} -r -w COPYING INSTALL Manual MySQL README \
		RELEASE_NOTES THEMES TODO UPGRADING ${ILOHAMAIL_DOC_DIR}
	${CHOWN} -R ${APACHE_USER}:${APACHE_GROUP} ${ILOHAMAIL_DIR}

.include "../../mk/bsd.pkg.mk"
