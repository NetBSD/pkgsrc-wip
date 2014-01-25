# $NetBSD: Makefile,v 1.8 2014/01/25 10:38:19 thomasklausner Exp $

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

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PYTHON_VERSIONED_DEPENDENCIES=	cairo

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../wip/igraph/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
