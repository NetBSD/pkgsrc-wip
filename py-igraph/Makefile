# $NetBSD: Makefile,v 1.2 2010/06/13 22:47:14 thomasklausner Exp $
#

DISTNAME=	python-igraph-0.5.3
PKGNAME=	${PYPKGPREFIX}-igraph-0.5.3
PKGREVISION=	1
CATEGORIES=	graphics math python
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-igraph/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://igraph.sourceforge.net/
COMMENT=	Manipulating Undirected And Directed Graphs for Python
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED= 26 25 24


.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../wip/igraph/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
