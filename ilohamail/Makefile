# $NetBSD: Makefile,v 1.15 2006/05/24 01:19:40 ykomatsu Exp $
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
ILOHAMAIL_DATA_DIR=	${VARBASE}/ilohamail/data
ILOHAMAIL_DATA_DIRS=	cache gpg sessions uploads users
ILOHAMAIL_DIR_PERMS=	${APACHE_USER} ${APACHE_GROUP} 0755
ILOHAMAIL_FILE_PERMS=	${APACHE_USER} ${APACHE_GROUP} 0644
ILOHAMAIL_CONF_FILES=	conf.inc conf.php custom_auth.php db_conf.php \
			defaults.generic.inc defaults.inc login.php \
			login_blurb.inc login_title.inc new_user.php
EGDIR=			${PREFIX}/share/examples/ilohamail
OWN_DIRS_PERMS=		${ILOHAMAIL_CONF_DIR} ${ILOHAMAIL_DIR_PERMS}
OWN_DIRS_PERMS+=	${ILOHAMAIL_DATA_DIR} ${ILOHAMAIL_DIR_PERMS}
.for dir in ${ILOHAMAIL_DATA_DIRS}
OWN_DIRS_PERMS+=	${ILOHAMAIL_DATA_DIR}/${dir} ${ILOHAMAIL_DIR_PERMS}
.endfor
.for file in ${ILOHAMAIL_CONF_FILES}
CONF_FILES_PERMS+=	${EGDIR}/conf/${file} ${ILOHAMAIL_CONF_DIR}/${file} \
			${ILOHAMAIL_FILE_PERMS}
.endfor

SUBST_CLASSES+=		ilohamail
SUBST_STAGE.ilohamail=	post-patch
SUBST_FILES.ilohamail=	IlohaMail/conf/conf.php
SUBST_SED.ilohamail=	-e "s|@ILOHAMAIL_DATA_DIR@|${ILOHAMAIL_DATA_DIR}|g"

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
