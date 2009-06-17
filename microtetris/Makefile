# $NetBSD: Makefile,v 1.3 2009/06/18 00:28:17 jihbed Exp $
#

DISTNAME=	microtetris
PKGNAME=	${DISTNAME}-0.1
CATEGORIES=	games python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=microtetris/}
EXTRACT_SUFX=	.py

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://microtetris.sourceforge.net/
COMMENT=	MicroTetris is a simple and compact popular game Tetris

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
NO_BUILD=	yes


INSTALLATION_DIRS=	bin

REPLACE_PYTHON+=        ${DISTNAME}.py

do-install:
	${CHMOD} +x ${WRKSRC}/${DISTNAME}.py
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}.py \
	    ${DESTDIR}${PREFIX}/bin/${DISTNAME}


.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
