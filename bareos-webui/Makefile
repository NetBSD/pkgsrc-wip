# $NetBSD: $

GITHUB_PROJECT=	bareos
VERSION=	19.2.8
GITHUB_TAG=	Release/${VERSION}

DISTNAME=	bareos-${VERSION}
PKGNAME=	${DISTNAME:S/-/-webui-/}
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG:C/\//-/}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=bareos/}

MAINTAINER=	mp@petermann-it.de
HOMEPAGE=	http://www.bareos.org/
COMMENT=	Backup Archiving REcovery Open Sourced - Web UI
LICENSE=	gnu-agpl-v3

USE_LANGUAGES=	# none

NO_BUILD=	yes

USE_TOOLS+=	bash:run pax perl:run

WEBUI_DIR=	share/bareos-webui

.include "../../mk/bsd.prefs.mk"

APACHE_USER?=	nginx
APACHE_GROUP?=	nginx
PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}

PKG_USERS_VARS=		APACHE_USER
PKG_GROUPS_VARS=	APACHE_GROUP

BUILD_DEFS+=	APACHE_GROUP APACHE_USER
FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		WEBUI_DIR=${WEBUI_DIR}

do-install:	
	cd ${WRKSRC} && ${FIND} webui -type f \
		\! -name '.*' \
		\! -name 'CMakeLists.txt' \
		\! -path 'webui/debian/*' \
		\! -path 'webui/cmake/*' \
		\! -path 'webui/doxygen/*' \
		-print | \
		pax -rw -pmp ${DESTDIR}${PREFIX}/share
	cd ${DESTDIR}${PREFIX}/share && mv webui bareos-webui

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
