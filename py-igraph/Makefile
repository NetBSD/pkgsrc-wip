# $NetBSD: Makefile,v 1.4 2012/02/10 09:01:10 noud4 Exp $
#

DISTNAME=	python-igraph-0.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S|python-||}
PKGREVISION=	2
CATEGORIES=	graphics math python
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-igraph/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://igraph.sourceforge.net/
COMMENT=	Manipulating Undirected And Directed Graphs for Python
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED= 27 26 25 24

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../wip/igraph/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
