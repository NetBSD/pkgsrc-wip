# $NetBSD: Makefile,v 1.6 2004/05/02 04:27:09 blef Exp $
#

DISTNAME=	streamripper-1.32
CATEGORIES=	audio
MASTER_SITES=	http://streamripper.sourceforge.net/files/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://streamripper.sourceforge.net/
COMMENT=	Splits SHOUTcast stream into tracks

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/streamripper ${PREFIX}/bin
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/streamripper
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/streamripper
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/streamripper
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/streamripper
	${INSTALL_DATA} ${WRKSRC}/THANKS ${PREFIX}/share/doc/streamripper
	${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/doc/streamripper

PTHREAD_OPTS+=	require

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
