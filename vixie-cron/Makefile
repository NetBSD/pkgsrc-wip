# $NetBSD: Makefile,v 1.2 2003/08/29 10:31:26 thomasklausner Exp $

DISTNAME=		cron_4.0_b1
PKGNAME=		vixie-cron-4.0.1
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.isc.org/isc/cron/
EXTRACT_SUFX=		.shar

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Execute and maintain scheduled commands

USE_PKGINSTALL=		YES

#WRKSRC=			${WRKDIR}
EXTRACT_CMD=	${MKDIR} ${WRKSRC} && cd ${WRKSRC} && ${CAT} ${DOWNLOADED_DISTFILE} | ${SH}
MAKE_ENV+=		DESTDIR=${PREFIX}

RCD_SCRIPTS=		cron

.include "../../mk/bsd.pkg.mk"
