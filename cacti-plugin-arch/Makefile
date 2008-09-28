# $NetBSD: Makefile,v 1.2 2008/09/28 10:46:29 pettai Exp $
#

DISTNAME=		cacti-plugin-arch
PKGNAME=		${DISTNAME}-2.1
CATEGORIES=		net
MASTER_SITES=		http://cactiusers.org/downloads/

MAINTAINER=		pettai@nordu.net
HOMEPAGE=		http://cactiusers.org/
COMMENT=		Plugin architecture for cacti

USE_LANGUAGES=		# none
NO_BUILD=		yes
WRKSRC=			${WRKDIR}/${DISTNAME}

DEPENDS+=		cacti-0.8.7b:../../wip/cacti

PKG_DESTDIR_SUPPORT=	user-destdir

CACTIDIR=		${PREFIX}/share/cacti

MESSAGE_SUBST+=         CACTIDIR=${CACTIDIR}

INSTALLATION_DIRS+=	share/cacti

do-install:
	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${DESTDIR}${CACTIDIR}/docs/
	${INSTALL_DATA} ${WRKSRC}/pa.sql ${DESTDIR}${CACTIDIR}/
	${CP} -R ${WRKSRC}/files-0.8.7b/* ${DESTDIR}${CACTIDIR}/

.include "../../mk/bsd.pkg.mk"
