# $NetBSD: Makefile,v 1.1.1.1 2009/03/13 18:31:11 jihbed Exp $
#

DISTNAME=	microtetris
PKGNAME=	${DISTNAME}-0.1
CATEGORIES=	games python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=microtetris/}
EXTRACT_SUFX=	.py

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://microtetris.sourceforge.net/
COMMENT=	MicroTetris is a simple and compact popular game Tetris

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/microtetris.py
USE_LANGUAGES=	# none
NO_BUILD=	yes
PYTHON_VERSIONS_ACCEPTED=  25

REPLACE_PYTHON+=        ${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC} \
	    ${DESTDIR}${PREFIX}/bin/${DISTNAME}
	${CHMOD} +x ${DESTDIR}${PREFIX}/bin/${DISTNAME}


.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
