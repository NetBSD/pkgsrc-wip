# $NetBSD: Makefile,v 1.4 2015/06/10 13:43:16 ahp-nils Exp $

DISTNAME=		realtime-v${VERSION}
PKGNAME=		cacti-plugin-realtime-${VERSION}
CATEGORIES=		net
MASTER_SITES=		http://docs.cacti.net/_media/plugin:

MAINTAINER=		nils@NetBSD.org
HOMEPAGE=		http://docs.cacti.net/
COMMENT=		Provides a method to view Cacti graphs with a resolution of upto 5 sec
LICENSE=		gnu-gpl-v2

VERSION=		0.5-2
EXTRACT_SUFX=		.tgz

USE_LANGUAGES=		# none
NO_BUILD=		yes
WRKSRC=			${WRKDIR}/realtime

EXTRACT_USING=		gtar
BUILD_DEPENDS+=		gtar-[0-9]*:../../archivers/gtar
DEPENDS+=		cacti>=0.8.7:../../net/cacti

USE_TOOLS+=		gtar
USE_TOOLS+=		pax

CACTIDIR=		${PREFIX}/share/cacti
PLUGINDIR=		${CACTIDIR}/plugins/realtime

MESSAGE_SUBST+=		CACTIDIR=${CACTIDIR}
MESSAGE_SUBST+=		PLUGINDIR=${PLUGINDIR}

INSTALLATION_DIRS+=	${PLUGINDIR}

do-install:
	cd ${WRKSRC} && ${PAX} -wr * ${DESTDIR}${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
