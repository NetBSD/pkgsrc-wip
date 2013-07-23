# $NetBSD: Makefile,v 1.1 2013/07/23 16:39:01 ahp-nils Exp $
#

DISTNAME=		rrdclean-v${VERSION}
PKGNAME=		cacti-plugin-rrdclean-${VERSION}
CATEGORIES=		net
MASTER_SITES=		http://docs.cacti.net/_media/plugin:

MAINTAINER=		ahp-nils@users.sourceforge.net
HOMEPAGE=		http://docs.cacti.net/plugin:rrdclean
COMMENT=		Cacti RRD File Cleaner
LICENSE=		gnu-gpl-v2

VERSION=		0.41
EXTRACT_SUFX=		.tgz

USE_LANGUAGES=		# none
NO_BUILD=		yes
WRKSRC=			${WRKDIR}/rrdclean

EXTRACT_USING=		gtar
BUILD_DEPENDS+=		gtar-[0-9]*:../../archivers/gtar
DEPENDS+=		cacti>=0.8.7g:../../net/cacti

USE_TOOLS+=		gtar
USE_TOOLS+=		pax

CACTIDIR=		${PREFIX}/share/cacti
PLUGINDIR=		${CACTIDIR}/plugins/rrdclean

MESSAGE_SUBST+=		CACTIDIR=${CACTIDIR}
MESSAGE_SUBST+=		PLUGINDIR=${PLUGINDIR}

INSTALLATION_DIRS+=	${PLUGINDIR}

do-install:
	cd ${WRKSRC} && ${PAX} -wr * ${DESTDIR}${PLUGINDIR}

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
