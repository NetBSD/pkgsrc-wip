# $NetBSD: Makefile,v 1.8 2010/03/16 20:15:10 pettai Exp $
#

DISTNAME=		gallery-2.2.6-full
PKGNAME=		gallery2-2.2.6
#PKGREVISION=		1
CATEGORIES=		www graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gallery/}

MAINTAINER=		pettai@nordu.net
HOMEPAGE=		http://gallery.sourceforge.net/
COMMENT=		Web-based photo gallery written in PHP
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# none
USE_TOOLS=		pax

DEPENDS+=		${PHP_PKG_PREFIX}-gd>=5.0.4:../../graphics/php-gd
DEPENDS+=		${PHP_PKG_PREFIX}-gettext>=5.0.4:../../devel/php-gettext
DEPENDS+=		${PHP_PKG_PREFIX}-{,mysql,pgsql}:../../databases/php-mysql

NO_BUILD=		yes
WRKSRC=			${WRKDIR}/gallery2

REPLACE_PERL=		lib/tools/po/*.pl

PKG_SYSCONFDIR=		${G2DIR}

PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_USERS_VARS+=	APACHE_USER
BUILD_DEFS+=		VARBASE

EGDIR=			${PREFIX}/share/examples/gallery2
G2DIR=			${PREFIX}/share/gallery2
DATADIR=		${VARBASE}/gallery2
G2DATA=			${DATADIR}/g2data

CONF_FILES_PERMS=	${DESTDIR}${EGDIR}/config.php ${DESTDIR}${G2DIR}/config.php \
			${ROOT_USER} ${ROOT_GROUP} 0644

MESSAGE_SUBST+=		G2DIR=${G2DIR}
MESSAGE_SUBST+=		G2DATA=${G2DATA}
FILES_SUBST+=		G2DIR=${G2DIR}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/gallery2.conf
SUBST_FILES.paths+=	${WRKDIR}/config.php
SUBST_FILES.paths+=	${WRKSRC}/lib/tools/po/extract.php
SUBST_VARS.paths+=	G2DIR G2DATA PREFIX
SUBST_STAGE.paths=	post-patch

OWN_DIRS_PERMS+=	${G2DATA} ${APACHE_USER} ${APACHE_GROUP} 755

INSTALLATION_DIRS=	share/examples/gallery2
INSTALLATION_DIRS+=	share/gallery2
INSTALLATION_DIRS+=	${G2DATA}

post-extract:
	${CP} ${FILESDIR}/gallery2.conf ${WRKDIR}/
	${CP} ${FILESDIR}/config.php ${WRKDIR}/
	#${CP} ${FILESDIR}/GalleryTemplateAdapter.class.NetBSD-patch ${WRKSRC}/
	#${CP} ${FILESDIR}/ALL.theme.tpl.NetBSD-patch ${WRKSRC}/

do-install:
	${INSTALL_DATA} ${WRKDIR}/gallery2.conf ${DESTDIR}${EGDIR}/gallery2.conf
	${INSTALL_DATA} ${WRKDIR}/config.php ${DESTDIR}${EGDIR}/config.php
	${INSTALL_DATA} ${FILESDIR}/.htaccess ${DESTDIR}${G2DIR}/.htaccess
	cd ${WRKSRC} && {PAX} -rwppm . ${DESTDIR}${G2DIR}/
	#${INSTALL_DATA} ${FILESDIR}/*.png ${DESTDIR}${G2DIR}/images/

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
