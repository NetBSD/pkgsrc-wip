# $NetBSD: Makefile,v 1.10 2013/06/04 07:45:22 thomasklausner Exp $

DISTNAME=	Py2Play-0.1.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://download.gna.org/slune/

MAINTAINER=	pkgsrc-users@NetBSD.org
# HOMEPAGE=	http://oomadness.tuxfamily.org/en/py2play/index.html
COMMENT=	Network game engine in Python, utilizing P2P model

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
