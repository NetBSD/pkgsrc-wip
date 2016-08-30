# $NetBSD: Makefile,v 1.9 2014/12/31 13:58:32 thomasklausner Exp $

DISTNAME=	python-igraph-0.7.1.post6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S|python-||}
CATEGORIES=	graphics math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-igraph/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://igraph.org/
COMMENT=	Manipulating Undirected and Directed Graphs for Python
LICENSE=	gnu-gpl-v2

PYTHON_VERSIONED_DEPENDENCIES=	cairo

USE_TOOLS+=	pkg-config

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../wip/igraph/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
