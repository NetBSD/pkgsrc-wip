# $NetBSD: Makefile,v 1.3 2012/10/07 13:57:27 asau Exp $
#

VERS=			1.1
DISTNAME=		pygraphviz-${VERS}
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		graphics
MASTER_SITES=	http://pypi.python.org/packages/source/p/pygraphviz/

MAINTAINER=		helgoman@users.sourceforge.net
HOMEPAGE=		http://networkx.lanl.gov/pygraphviz/index.html
COMMENT=		Python interface to the Graphviz package
LICENSE=		original-bsd

PYDISTUTILSPKG=		yes

.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
