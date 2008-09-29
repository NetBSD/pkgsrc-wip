# $NetBSD: Makefile,v 1.1.1.1 2008/09/29 23:44:14 pettai Exp $
#

DISTNAME=		tools-0.3
PKGNAME=		cacti-plugin-${DISTNAME}
CATEGORIES=		net
MASTER_SITES=		http://mirror.cactiusers.org/downloads/plugins/

MAINTAINER=		pettai@nordu.net
HOMEPAGE=		http://mirror.cactiusers.org/downloads/plugins/
COMMENT=		Tools plugin to cacti

USE_LANGUAGES=		# none
NO_BUILD=		yes
WRKSRC=			${WRKDIR}/tools

BUILD_DEPENDS+=		gtar-[0-9]*:../../archivers/gtar
DEPENDS+=		cacti-plugin-arch-[0-9]*:../../wip/cacti-plugin-arch

USE_TOOLS+=		gtar

PKG_DESTDIR_SUPPORT=	user-destdir

CACTIDIR=		${PREFIX}/share/cacti
PLUGINDIR=		${CACTIDIR}/plugins/tools

MESSAGE_SUBST+=		CACTIDIR=${CACTIDIR}

INSTALLATION_DIRS+=	${PLUGINDIR}

do-extract:
	${GTAR} xzf ${DISTDIR}/${DISTNAME}.tar.gz -C ${WRKDIR}

do-install:
	${CP} -R ${WRKSRC}/* ${DESTDIR}${PLUGINDIR}

WRKSRC=		${WRKDIR}/tools
USE_LANGUAGES=	# none

.include "../../mk/bsd.pkg.mk"
