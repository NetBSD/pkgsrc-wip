# $NetBSD: Makefile,v 1.1.1.1 2003/08/15 18:23:49 tvierling Exp $
#

DISTNAME=		ASFRecorder
PKGNAME=		asfrecorder-1.1
WRKSRC=			${WRKDIR}/ASFRecorder/source
CATEGORIES=		local
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=asfrecorder/}
EXTRACT_SUFX=		.zip

MAINTAINER=		tv@pobox.com
HOMEPAGE=		http://asfrecorder.sourceforge.net/
COMMENT=		Static-file downloader for ASF streaming media

USE_BUILDLINK2=		yes

do-build:
	cd ${WRKSRC} && ${LINK.c} -o asfrecorder asfrecorder.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asfrecorder ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
