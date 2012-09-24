# $NetBSD: Makefile,v 1.5 2012/09/24 18:26:51 asau Exp $
#

DISTNAME=		php-weathermap-0.96a
PKGNAME=		cacti-plugin-weathermap-0.96a
CATEGORIES=		net
MASTER_SITES=		http://www.network-weathermap.com/files/
EXTRACT_SUFX=		.zip

MAINTAINER=		pettai@nordu.net
HOMEPAGE=		http://www.network-weathermap.com/
COMMENT=		Php Weathermap, as a plugin to cacti
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/weathermap
USE_LANGUAGES=		# none
NO_BUILD=		yes

DEPENDS+=		cacti>=0.8.7h:../../net/cacti

CACTI_USER?=		cacti
CACTI_GROUP?=		cacti

CACTIDIR=		${PREFIX}/share/cacti
PLUGINDIR=		${CACTIDIR}/plugins/weathermap

MESSAGE_SUBST+=		CACTIDIR=${CACTIDIR}
MESSAGE_SUBST+=		PLUGINDIR=${PLUGINDIR}

OWN_DIRS_PERMS+=        ${PLUGINDIR}/configs ${CACTI_USER} ${CACTI_GROUP} 0755
OWN_DIRS_PERMS+=        ${PLUGINDIR}/output ${CACTI_USER} ${CACTI_GROUP} 0755

INSTALLATION_DIRS+=	${PLUGINDIR}

do-install:
	${CP} -R ${WRKSRC}/* ${DESTDIR}${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
