# $NetBSD: Makefile,v 1.1.1.1 2010/03/06 13:07:11 helgoman Exp $
#

DISTNAME=		eric4-4.4.1
PKGREVISION=	1
CATEGORIES=		devel
MASTER_SITES=	http://downloads.sourceforge.net/project/eric-ide/eric4/stable/4.4.1/

MAINTAINER=		helgoman@users.sourceforge.net
HOMEPAGE=		http://eric-ide.python-projects.org/index.html
COMMENT=		Python - IDE
LICENSE=		gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=          yes
PYSETUP=				install.py -b ${PREFIX}/bin
PYDISTUTILSPKG=			yes

.include "../../lang/python/extension.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../wip/qt4-qscintilla/buildlink3.mk"
.include "../../wip/py-qt4-qscintilla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
