# $NetBSD: Makefile,v 1.3 2003/09/25 02:45:17 tvierling Exp $
#

DISTNAME=		ASFRecorder
PKGNAME=		asfrecorder-1.1
WRKSRC=			${WRKDIR}/ASFRecorder/source
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=asfrecorder/}
EXTRACT_SUFX=		.zip

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://asfrecorder.sourceforge.net/
COMMENT=		Static-file downloader for ASF streaming media

USE_BUILDLINK2=		yes

do-build:
	cd ${WRKSRC} && ${LINK.c} -o asfrecorder asfrecorder.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asfrecorder ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
