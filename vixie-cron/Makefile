# $NetBSD: Makefile,v 1.7 2006/10/16 18:41:15 ondratu Exp $

DISTNAME=		cron_4.1
PKGNAME=		vixie-cron-4.1
CATEGORIES=		sysutils time
MASTER_SITES=		ftp://ftp.isc.org/isc/cron/
EXTRACT_SUFX=		.shar

MAINTAINER=		reed@reedmedia.net
COMMENT=		Execute and maintain scheduled commands

#WRKSRC=			${WRKDIR}
EXTRACT_CMD=	${MKDIR} ${WRKSRC} && cd ${WRKSRC} && ${CAT} ${DOWNLOADED_DISTFILE} | ${SH}
MAKE_ENV+=		DESTDIR=${PREFIX:Q}

RCD_SCRIPTS=		cron

.include "../../mk/bsd.pkg.mk"
