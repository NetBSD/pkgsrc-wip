# $NetBSD: Makefile,v 1.9 2013/02/20 08:25:09 ahp-nils Exp $
#

DISTNAME=		thold-v${VERSION}
PKGNAME=		cacti-plugin-thold-${VERSION}
CATEGORIES=		net
MASTER_SITES=		http://docs.cacti.net/_media/plugin:

MAINTAINER=		pettai@nordu.net
HOMEPAGE=		http://docs.cacti.net/
COMMENT=		Treshold plugin to cacti
LICENSE=		gnu-gpl-v2

VERSION=		0.4.9-3
EXTRACT_SUFX=		.tgz

USE_LANGUAGES=		# none
NO_BUILD=		yes
WRKSRC=			${WRKDIR}/thold

EXTRACT_USING=		gtar
BUILD_DEPENDS+=		gtar-[0-9]*:../../archivers/gtar
DEPENDS+=		cacti>=0.8.7:../../net/cacti

USE_TOOLS+=		gtar
USE_TOOLS+=		pax

CACTIDIR=		${PREFIX}/share/cacti
PLUGINDIR=		${CACTIDIR}/plugins/thold

MESSAGE_SUBST+=		CACTIDIR=${CACTIDIR}
MESSAGE_SUBST+=		PLUGINDIR=${PLUGINDIR}

INSTALLATION_DIRS+=	${PLUGINDIR}

do-install:
	cd ${WRKSRC} && ${PAX} -wr * ${DESTDIR}${PLUGINDIR}

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
