# $NetBSD: Makefile,v 1.2 2003/06/03 16:32:43 xtraeme Exp $
#

DISTNAME=	weewm-0.01
WRKSRC=         ${WRKDIR}/weewm
CATEGORIES=	wm
MASTER_SITES=	http://www.weewm.org/download/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.weewm.org/
COMMENT=	Fast and ultra light windowmanager with total keyboard control

USE_BUILDLINK2=		yes
USE_X11=		yes

EXAMPLESDIR=	${PREFIX}/share/examples/weewm
DOCDIR=		${PREFIX}/share/doc/weewm

do-install:
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/weewm ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/keys.rc ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/INSTALL ${WRKSRC}/FAQ \
		${DOCDIR}

.include "../../mk/bsd.pkg.mk"
