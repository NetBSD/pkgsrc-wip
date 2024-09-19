# $NetBSD: Makefile,v 1.2 2012/10/05 13:52:03 asau Exp $
#

DISTNAME=	probcons_v1_12
PKGNAME=	probcons-1.12
CATEGORIES=	biology
MASTER_SITES=	http://probcons.stanford.edu/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://probcons.stanford.edu/
COMMENT=	Probabilistic Consistency-based Multiple Alignment of Amino Acid Sequences

WRKSRC=		${WRKDIR}/probcons

USE_LANGUAGES=	c++

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/compare ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/makegnuplot ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/probcons ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/project ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
