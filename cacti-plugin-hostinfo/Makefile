# $NetBSD: Makefile,v 1.2 2008/09/28 12:00:59 pettai Exp $
#

DISTNAME=		hostinfo-0.2
PKGNAME=		cacti-plugin-${DISTNAME}
CATEGORIES=		net
MASTER_SITES=		http://cactiusers.org/downloads/

MAINTAINER=		pettai@nordu.net
HOMEPAGE=		http://cactiusers.org/
COMMENT=		Host info plugin for cacti

USE_LANGUAGES=		# none
NO_BUILD=		yes
WRKSRC=			${WRKDIR}/hostinfo

BUILD_DEPENDS+=		gtar-[0-9]*:../../archivers/gtar
DEPENDS+=		cacti-plugin-arch-[0-9]*:../../wip/cacti-plugin-arch

USE_TOOLS+=		gtar

PKG_DESTDIR_SUPPORT=	user-destdir

CACTIDIR=		${PREFIX}/share/cacti
PLUGINDIR=		${CACTIDIR}/plugins/hostinfo

MESSAGE_SUBST+=		CACTIDIR=${CACTIDIR}

INSTALLATION_DIRS+=	${PLUGINDIR}

do-extract:
	${GTAR} xzf ${DISTDIR}/${DISTNAME}.tar.gz -C ${WRKDIR}

do-install:
	${CP} -R ${WRKSRC}/* ${DESTDIR}${PLUGINDIR}

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
