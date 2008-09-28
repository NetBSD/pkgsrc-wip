# $NetBSD: Makefile,v 1.1.1.1 2008/09/28 01:09:07 pettai Exp $
#

DISTNAME=		php-weathermap-0.95b
PKGNAME=		cacti-plugin-weathermap-0.95b
CATEGORIES=		net
MASTER_SITES=		http://www.network-weathermap.com/files/
EXTRACT_SUFX=		.zip

MAINTAINER=		pettai@nordu.net
HOMEPAGE=		http://www.network-weathermap.com/
COMMENT=		Php Weathermap, as a plugin to cacti

WRKSRC=			${WRKDIR}/weathermap
USE_LANGUAGES=		# none
NO_BUILD=		yes

DEPENDS+=		cacti-plugin-arch:../../wip/cacti-plugin-arch

PKG_DESTDIR_SUPPORT=	user-destdir

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
