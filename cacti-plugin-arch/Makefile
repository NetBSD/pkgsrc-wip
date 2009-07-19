# $NetBSD: Makefile,v 1.4 2009/07/19 22:33:36 pettai Exp $
#
DISTNAME=		cacti-plugin-${CACTI_RC}-PA-v${RC_VERSION}
PKGNAME=		cacti-plugin-arch-${RC_VERSION}
CATEGORIES=		net
MASTER_SITES=		http://mirror.cactiusers.org/downloads/plugins/
EXTRACT_SUFX=		.zip
RC_VERSION=		2.5
CACTI_RC=		0.8.7e

MAINTAINER=		pettai@nordu.net
HOMEPAGE=		http://cactiusers.org/
COMMENT=		Plugin architecture for cacti
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		# none
NO_BUILD=		yes
WRKSRC=			${WRKDIR}/files-${CACTI_RC}

DEPENDS+=		cacti-0.8.7e:../../wip/cacti

PKG_DESTDIR_SUPPORT=	user-destdir

CACTIDIR=		${PREFIX}/share/cacti

MESSAGE_SUBST+=         CACTIDIR=${CACTIDIR}

INSTALLATION_DIRS+=	share/cacti

do-install:
	${INSTALL_DATA} ${WRKDIR}/readme.txt ${DESTDIR}${CACTIDIR}/docs/
	${INSTALL_DATA} ${WRKDIR}/pa.sql ${DESTDIR}${CACTIDIR}/
	${CP} -R ${WRKSRC}/* ${DESTDIR}${CACTIDIR}/

.include "../../mk/bsd.pkg.mk"
