# $NetBSD: Makefile,v 1.5 2012/09/24 18:26:51 asau Exp $

DISTNAME=		hostinfo-0.2
PKGNAME=		cacti-plugin-${DISTNAME}
CATEGORIES=		net
MASTER_SITES=		http://mirror.cactiusers.org/downloads/plugins/

MAINTAINER=		pettai@nordu.net
HOMEPAGE=		http://cactiusers.org/
COMMENT=		Host info plugin for cacti

USE_LANGUAGES=		# none
NO_BUILD=		yes
WRKSRC=			${WRKDIR}/hostinfo

BUILD_DEPENDS+=		gtar-[0-9]*:../../archivers/gtar
DEPENDS+=		cacti>=0.8.7h:../../net/cacti

USE_TOOLS+=		gtar

CACTIDIR=		${PREFIX}/share/cacti
PLUGINDIR=		${CACTIDIR}/plugins/hostinfo

MESSAGE_SUBST+=		CACTIDIR=${CACTIDIR}

INSTALLATION_DIRS+=	${PLUGINDIR}

do-extract:
	${GTAR} xzf ${DISTDIR}/${DISTNAME}.tar.gz -C ${WRKDIR}

do-install:
	${CP} -R ${WRKSRC}/* ${DESTDIR}${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
