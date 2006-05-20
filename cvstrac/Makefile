# $NetBSD: Makefile,v 1.1.1.1 2006/05/20 05:12:43 yomram Exp $
#

DISTNAME=	cvstrac-1.2.1
CATEGORIES=	devel www
MASTER_SITES=	http://www.cvstrac.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cvstrac.org/
COMMENT=	Web-Based Bug And Patch-Set Tracking System For CVS

pre-build:
	${CP} ${FILESDIR}/Makefile.in ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cvstrac ${PREFIX}/bin

.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
