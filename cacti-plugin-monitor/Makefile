# $NetBSD: Makefile,v 1.4 2012/09/24 18:26:51 asau Exp $
#

DISTNAME=		monitor-0.8.2
PKGNAME=		cacti-plugin-${DISTNAME}
CATEGORIES=		net
MASTER_SITES=		http://mirror.cactiusers.org/downloads/plugins/

MAINTAINER=		pettai@nordu.net
HOMEPAGE=		http://cactiusers.org/
COMMENT=		Monitor plugin to cacti


USE_LANGUAGES=		# none
NO_BUILD=		yes
WRKSRC=			${WRKDIR}/monitor

BUILD_DEPENDS+=		gtar-[0-9]*:../../archivers/gtar
DEPENDS+=		cacti>=0.8.7h:../../net/cacti

USE_TOOLS+=		gtar

CACTIDIR=		${PREFIX}/share/cacti
PLUGINDIR=		${CACTIDIR}/plugins/monitor

MESSAGE_SUBST+=		CACTIDIR=${CACTIDIR}
MESSAGE_SUBST+=		PLUGINDIR=${PLUGINDIR}

INSTALLATION_DIRS+=	${PLUGINDIR}

do-extract:
	${GTAR} xzf ${DISTDIR}/${DISTNAME}.tar.gz -C ${WRKDIR}

do-install:
	${CP} -R ${WRKSRC}/* ${DESTDIR}${PLUGINDIR}

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
