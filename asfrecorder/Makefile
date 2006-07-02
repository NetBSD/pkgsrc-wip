# $NetBSD: Makefile,v 1.7 2006/07/02 19:04:33 shattered Exp $
#

DISTNAME=		ASFRecorder
PKGNAME=		asfrecorder-1.1
WRKSRC=			${WRKDIR}/ASFRecorder/source
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=asfrecorder/}
EXTRACT_SUFX=		.zip

MAINTAINER=		tv@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/asfrecorder/
COMMENT=		Static-file downloader for ASF streaming media

do-build:
	cd ${WRKSRC} && ${LINK.c} -o asfrecorder asfrecorder.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asfrecorder ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
