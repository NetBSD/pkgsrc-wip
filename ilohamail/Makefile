# $NetBSD: Makefile,v 1.20 2012/09/30 05:30:23 asau Exp $
#

DISTNAME=	IlohaMail-0.8.14-rc3
PKGNAME=	ilohamail-0.8.14rc3
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ilohamail/}
LICENSE=	gnu-gpl-v2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://blog.ilohamail.org/
COMMENT=	Light weight yet full featured multilingual webmail

DEPENDS+=	${PHP_PKG_PREFIX}-imap>=4.3.3:../../mail/php-imap

PKG_DESTDIR_SUPPORT=	destdir

NO_BUILD=	yes
USE_TOOLS+=	pax

APACHE_USER?=	www
APACHE_GROUP?=	www
PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}
BUILD_DEFS+=	APACHE_USER APACHE_GROUP

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
SUBST_VARS.ilohamail=	ILOHAMAIL_DATA_DIR

pre-install:
	${FIND} ${WRKSRC} -name "*.orig" -print -type f | ${XARGS} ${RM} -f

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${ILOHAMAIL_DIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${ILOHAMAIL_DOC_DIR}
	cd ${WRKSRC}/IlohaMail && pax -r -w data include index.html lang \
		source ${DESTDIR}${ILOHAMAIL_DIR}
	cd ${WRKSRC}/IlohaMail && pax -r -w conf ${DESTDIR}${EGDIR}
	cd ${WRKSRC} && pax -r -w COPYING INSTALL Manual MySQL README \
		RELEASE_NOTES THEMES TODO UPGRADING ${DESTDIR}${ILOHAMAIL_DOC_DIR}
	${CHOWN} -R ${APACHE_USER}:${APACHE_GROUP} ${DESTDIR}${ILOHAMAIL_DIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
