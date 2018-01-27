# $NetBSD: Makefile,v 1.8 2014/05/09 07:38:43 thomasklausner Exp $

DISTNAME=	microtetris
PKGNAME=	${DISTNAME}-0.1
PKGREVISION=	1
CATEGORIES=	games python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=microtetris/}
EXTRACT_SUFX=	.py

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://microtetris.sourceforge.net/
COMMENT=	MicroTetris is a simple and compact popular game Tetris

DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS=	bin

REPLACE_PYTHON+=		${DISTNAME}.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-gtk2, py-gobject

do-install:
	${CHMOD} +x ${WRKSRC}/${DISTNAME}.py
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}.py \
	    ${DESTDIR}${PREFIX}/bin/${DISTNAME}


.include "../../devel/py-gobject/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
