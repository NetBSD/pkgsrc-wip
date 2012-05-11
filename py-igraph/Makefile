# $NetBSD: Makefile,v 1.6 2012/05/11 12:47:07 noud4 Exp $
#

DISTNAME=	python-igraph-0.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S|python-||}
EGG_NAME=	${DISTNAME:S|n-|n_|:Q}
PKGREVISION=	3
CATEGORIES=	graphics math python
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-igraph/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://igraph.sourceforge.net/
COMMENT=	Manipulating Undirected And Directed Graphs for Python
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../wip/igraph/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
