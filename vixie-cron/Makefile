# $NetBSD: Makefile,v 1.1.1.1 2003/04/19 17:24:14 jeremy-c-reed Exp $

DISTNAME=		cron_4.0_b1
PKGNAME=		vixie-cron-4.0.1
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.isc.org/isc/cron/
EXTRACT_SUFX=		.shar

MAINTAINER=		packages@NetBSD.ORG
COMMENT=		Execute and maintain scheduled commands

USE_PKGINSTALL=		YES

#WRKSRC=			${WRKDIR}
EXTRACT_CMD=	${MKDIR} ${WRKSRC} && cd ${WRKSRC} && ${CAT} ${DOWNLOADED_DISTFILE} | ${SH}
MAKE_ENV+=		DESTDIR=${PREFIX}

RCD_SCRIPTS=		cron

.include "../../mk/bsd.pkg.mk"
