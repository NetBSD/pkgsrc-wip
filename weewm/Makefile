# $NetBSD: Makefile,v 1.6 2004/05/09 21:48:15 blef Exp $
#

DISTNAME=	weewm-0.01
WRKSRC=         ${WRKDIR}/weewm
CATEGORIES=	wm
MASTER_SITES=	http://www.weewm.org/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.weewm.org/
COMMENT=	Fast and ultra light windowmanager with total keyboard control

USE_BUILDLINK3=		yes
USE_X11=		yes

EXAMPLESDIR=	${PREFIX}/share/examples/weewm
DOCDIR=		${PREFIX}/share/doc/weewm

do-install:
	${INSTALL_DATA_DIR} ${EXAMPLESDIR} ${DOCDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/weewm ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/keys.rc ${EXAMPLESDIR}
	( cd ${WRKSRC} && for file in README FAQ INSTALL; do \
		${INSTALL_DATA} $$file ${DOCDIR}; \
	done )

.include "../../mk/bsd.pkg.mk"
