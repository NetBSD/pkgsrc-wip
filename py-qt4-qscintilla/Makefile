# $NetBSD: Makefile,v 1.4 2010/06/13 22:47:14 thomasklausner Exp $
#

DISTNAME=			QScintilla-gpl-2.4.3
PKGNAME=			${PYPKGPREFIX}-qt4-${DISTNAME:tl:S/-gpl-/-/}
PKGREVISION=		3
CATEGORIES=			x11
MASTER_SITES=		http://www.riverbankcomputing.com/static/Downloads/QScintilla2/

MAINTAINER=			helgoman@users.sourceforge.net
HOMEPAGE=			http://www.riverbankcomputing.co.uk/software/qscintilla/intro
COMMENT=			QScintilla -- Python bindings --
LICENSE=			gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=				${WRKDIR}/${DISTNAME}/Python

USE_LIBTOOL=		yes
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
