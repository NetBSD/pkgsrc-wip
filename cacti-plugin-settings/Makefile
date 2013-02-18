# $NetBSD: Makefile,v 1.4 2013/02/18 09:42:59 ahp-nils Exp $
#

DISTNAME=		settings-v${VERSION}
PKGNAME=		cacti-plugin-settings-${VERSION}
CATEGORIES=		net
MASTER_SITES=		http://docs.cacti.net/_media/

MAINTAINER=		pettai@nordu.net
HOMEPAGE=		http://docs.cacti.net/
COMMENT=		Settings plugin to cacti
LICENSE=		gnu-gpl-v2

VERSION=		0.71-1
EXTRACT_SUFX=		.tgz

USE_LANGUAGES=		# none
NO_BUILD=		yes
WRKSRC=			${WRKDIR}/settings

EXTRACT_USING=		gtar
BUILD_DEPENDS+=		gtar-[0-9]*:../../archivers/gtar
BUILD_DEPENDS+=		curl-[0-9]*:../../www/curl
DEPENDS+=		cacti>=0.8.7:../../net/cacti

USE_TOOLS+=		gtar
USE_TOOLS+=		pax
USE_TOOLS+=		curl

PKG_DESTDIR_SUPPORT=	user-destdir

CACTIDIR=		${PREFIX}/share/cacti
PLUGINDIR=		${CACTIDIR}/plugins/settings

MESSAGE_SUBST+=		CACTIDIR=${CACTIDIR}
MESSAGE_SUBST+=		PLUGINDIR=${PLUGINDIR}

INSTALLATION_DIRS+=	${PLUGINDIR}

do-fetch:
	curl ${MASTER_SITES:Q}plugin:${DISTNAME}${EXTRACT_SUFX} -o ${DISTDIR}/settings-v${VERSION}${EXTRACT_SUFX}

do-install:
	cd ${WRKSRC} && ${PAX} -wr * ${DESTDIR}${PLUGINDIR}

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
