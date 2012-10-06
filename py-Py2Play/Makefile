# $NetBSD: Makefile,v 1.9 2012/10/06 17:13:26 asau Exp $
#

DISTNAME=	Py2Play-0.1.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://download.gna.org/slune/

MAINTAINER=	pkgsrc-users@NetBSD.org
# HOMEPAGE=	http://oomadness.tuxfamily.org/en/py2play/index.html
COMMENT=	Network game engine in Python, utilizing P2P model

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
