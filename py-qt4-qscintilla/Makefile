# $NetBSD: Makefile,v 1.1.1.1 2010/03/06 01:23:51 helgoman Exp $
#

DISTNAME=   		QScintilla-gpl-2.4.2
PKGNAME=			${PYPKGPREFIX}-qt4-qscintilla-2.4.2
PKGREVISION=		1
CATEGORIES=			x11
MASTER_SITES=		http://www.riverbankcomputing.com/static/Downloads/QScintilla2/

MAINTAINER=			helgoman@users.sourceforge.net
HOMEPAGE=			http://www.riverbankcomputing.com/static/Downloads/QScintilla2/
COMMENT=			QScintilla -- Python bindings --
LICENSE=			gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=            	${WRKDIR}/${DISTNAME}/Python

USE_TOOLS+=      	make
USE_LIBTOOL=     	yes
USE_LANGUAGES=		c++

PY_PATCHPLIST=		yes

do-configure:
		(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}  \
	  	${PYTHONBIN} configure.py)


.include "../../lang/python/extension.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../wip/qt4-qscintilla/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
