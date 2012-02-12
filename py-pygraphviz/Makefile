# $NetBSD: Makefile,v 1.2 2012/02/12 21:41:54 helgoman Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		yes

.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
