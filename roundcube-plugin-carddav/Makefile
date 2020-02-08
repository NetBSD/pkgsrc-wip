# $NetBSD: $

CONF_PLUGINS=	carddav
.include "../../mail/roundcube/Makefile.common"

DISTNAME=	carddav-3.0.3
PKGNAME=	${PHP_PKG_PREFIX}-roundcube-plugin-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=blind-coder/}
GITHUB_PROJECT=	rcmcarddav
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	https://www.benjamin-schieder.de/carddav.html
MAINTAINER=	triaxx@NetBSD.org
COMMENT=	CardDAV adapter for Roundcube
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-roundcube>=1.0.0:../../mail/roundcube

WRKSRC=		${WRKDIR}/carddav

DISTINFO_FILE=		distinfo

PKG_SYSCONFSUBDIR=	roundcube/plugins/carddav

CDDIR=			${RCDIR}/plugins/carddav

CD_SUBDIRS=		dbmigrations localization skins vendor

.for d in ${CD_SUBDIRS}
INSTALLATION_DIRS+=	${CDDIR}/${d}
.endfor

CONF_FILES_PERMS+=	${PREFIX}/${EGDIR}/plugins/carddav/config.inc.php \
			${PKG_SYSCONFDIR}/config.inc.php \
			${WWW_USER} ${WWW_GROUP} 0640

MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
SUBST_CLASSES+=		cfg
SUBST_STAGE.cfg=	pre-install
SUBST_MESSAGE.cfg=	Fixing configuration files.
SUBST_FILES.cfg=	carddav_common.php
SUBST_VARS.cfg=		PKG_SYSCONFDIR

do-install:
	${INSTALL_DATA} ${WRKSRC}/carddav.php \
		${DESTDIR}${PREFIX}/${CDDIR}/carddav.php
	${INSTALL_DATA} ${WRKSRC}/carddav_backend.php \
		${DESTDIR}${PREFIX}/${CDDIR}/carddav_backend.php
	${INSTALL_DATA} ${WRKSRC}/carddav_common.php \
		${DESTDIR}${PREFIX}/${CDDIR}/carddav_common.php
	${INSTALL_DATA} ${WRKSRC}/carddav_discovery.php \
		${DESTDIR}${PREFIX}/${CDDIR}/carddav_discovery.php
.for i in ${CD_SUBDIRS}
	cd ${WRKSRC}/${i} && ${FIND} . -type f -print | \
		pax -rw ${DESTDIR}${PREFIX}/${CDDIR}/${i}
	${FIND} ${DESTDIR}${PREFIX}/${CDDIR}/${i} -type f | \
		${XARGS} ${CHMOD} ${SHAREMODE}
	${FIND} ${DESTDIR}${PREFIX}/${CDDIR}/${i} -type d | \
		${XARGS} ${CHMOD} ${PKGDIRMODE}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} \
		${DESTDIR}${PREFIX}/${CDDIR}/${i}
.endfor
	${INSTALL_DATA} ${WRKSRC}/config.inc.php.dist \
		${DESTDIR}${PREFIX}/${CDDIR}/config.inc.php.dist

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
