# $NetBSD: Makefile,v 1.7 2014/05/27 11:54:23 ahp-nils Exp $
#

DISTNAME=		php-weathermap-0.97c
PKGNAME=		cacti-plugin-weathermap-0.97c
CATEGORIES=		net
MASTER_SITES=		http://www.network-weathermap.com/files/
EXTRACT_SUFX=		.zip

MAINTAINER=		pettai@nordu.net
HOMEPAGE=		http://www.network-weathermap.com/
COMMENT=		Generate maps and diagrams using data collected by Cacti
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/weathermap
USE_LANGUAGES=		# none
USE_TOOLS+=		pax
NO_BUILD=		yes

DEPENDS+=		cacti>=0.8.7:../../net/cacti

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		CACTI_USER
BUILD_DEFS+=		CACTI_GROUP

CACTI_USER?=		cacti
CACTI_GROUP?=		cacti

CACTIDIR=		${PREFIX}/share/cacti
PLUGINDIR=		${CACTIDIR}/plugins/weathermap

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*php[^ ]*
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	weathermap random-bits/query_weathermap_runtime.php

REPLACE_PERL+=		random-bits/auto-overlib.pl

MESSAGE_SUBST+=		CACTIDIR=${CACTIDIR}
MESSAGE_SUBST+=		PLUGINDIR=${PLUGINDIR}

OWN_DIRS_PERMS+=	${PLUGINDIR}/configs ${CACTI_USER} ${CACTI_GROUP} 0755
OWN_DIRS_PERMS+=	${PLUGINDIR}/output ${CACTI_USER} ${CACTI_GROUP} 0755

INSTALLATION_DIRS+=	${PLUGINDIR}

do-install:
	cd ${WRKSRC} && ${PAX} -wr * ${DESTDIR}${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
