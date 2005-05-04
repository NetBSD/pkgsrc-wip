# $NetBSD: Makefile,v 1.4 2005/05/04 01:19:28 jeremy-c-reed Exp $

DISTNAME=		cron_4.0_b1
PKGNAME=		vixie-cron-4.0.1
CATEGORIES=		sysutils time
MASTER_SITES=		ftp://ftp.isc.org/isc/cron/
EXTRACT_SUFX=		.shar

MAINTAINER=		reed@reedmedia.net
COMMENT=		Execute and maintain scheduled commands

USE_PKGINSTALL=		YES

#WRKSRC=			${WRKDIR}
EXTRACT_CMD=	${MKDIR} ${WRKSRC} && cd ${WRKSRC} && ${CAT} ${DOWNLOADED_DISTFILE} | ${SH}
MAKE_ENV+=		DESTDIR=${PREFIX}

RCD_SCRIPTS=		cron

.include "../../mk/bsd.pkg.mk"
