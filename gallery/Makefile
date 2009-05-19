# $NetBSD: Makefile,v 1.3 2009/05/19 09:00:07 thomasklausner Exp $
#

DISTNAME=	gallery-1.5.10
CATEGORIES=	www graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gallery/}

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://gallery.sourceforge.net/
COMMENT=	Web-based photo gallery written in PHP
LICENSE=	gnu-gpl-v2

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=4.1.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-gettext>=4.1.0:../../devel/php-gettext

PKG_SYSCONFDIR=	${G1DIR}
PKG_DESTDIR_SUPPORT=	user-destdir

EGDIR=		${PREFIX}/share/examples/gallery
G1DIR=		${PREFIX}/share/gallery

CONF_FILES_PERMS=	${DESTDIR}${EGDIR}/config.php ${DESTDIR}${G1DIR}/config.php \
			${ROOT_USER} ${ROOT_GROUP} 0666
CONF_FILES_PERMS+=	${DESTDIR}${EGDIR}/.htaccess ${DESTDIR}${G1DIR}/.htaccess \
			${ROOT_USER} ${ROOT_GROUP} 0666

MESSAGE_SUBST+=	G1DIR=${G1DIR}
FILES_SUBST+=	G1DIR=${G1DIR}

SUBST_CLASSES+=	paths
SUBST_FILES.paths=	${WRKDIR}/gallery.conf
SUBST_VARS.paths+=	G1DIR
SUBST_STAGE.paths=	post-patch

INSTALLATION_DIRS=	share/examples/gallery
INSTALLATION_DIRS+=	share/gallery

post-extract:
	${CP} ${FILESDIR}/gallery.conf ${WRKDIR}/
	#${CD} ${DESTDIR}${G1DIR}
	#./configure.sh
	${TOUCH} ${FILESDIR}/config.php
	${TOUCH} ${FILESDIR}/.htaccess

do-install:
	${INSTALL_DATA} ${WRKDIR}/gallery.conf ${DESTDIR}${EGDIR}/gallery.conf
	${INSTALL_DATA} ${FILESDIR}/config.php ${DESTDIR}${EGDIR}/config.php
	${INSTALL_DATA} ${FILESDIR}/.htaccess ${DESTDIR}${EGDIR}/.htaccess
	${CP} -R ${WRKSRC}/* ${DESTDIR}${G1DIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
