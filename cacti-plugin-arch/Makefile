# $NetBSD: Makefile,v 1.3 2009/04/06 22:25:44 pettai Exp $
#
DISTNAME=		cacti-plugin-${CACTI_RC}-PA-v${RC_VERSION}
PKGNAME=		cacti-plugin-arch-${RC_VERSION}
CATEGORIES=		net
MASTER_SITES=		http://mirror.cactiusers.org/downloads/plugins/
EXTRACT_SUFX=		.zip
RC_VERSION=		2.4
CACTI_RC=		0.8.7d

MAINTAINER=		pettai@nordu.net
HOMEPAGE=		http://cactiusers.org/
COMMENT=		Plugin architecture for cacti

USE_LANGUAGES=		# none
NO_BUILD=		yes
WRKSRC=			${WRKDIR}/files-${CACTI_RC}

DEPENDS+=		cacti-0.8.7d:../../wip/cacti

PKG_DESTDIR_SUPPORT=	user-destdir

CACTIDIR=		${PREFIX}/share/cacti

MESSAGE_SUBST+=         CACTIDIR=${CACTIDIR}

INSTALLATION_DIRS+=	share/cacti

do-install:
	${INSTALL_DATA} ${WRKDIR}/readme.txt ${DESTDIR}${CACTIDIR}/docs/
	${INSTALL_DATA} ${WRKDIR}/pa.sql ${DESTDIR}${CACTIDIR}/
	${CP} -R ${WRKSRC}/* ${DESTDIR}${CACTIDIR}/

.include "../../mk/bsd.pkg.mk"
