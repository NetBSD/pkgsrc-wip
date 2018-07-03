# $NetBSD: Makefile,v 1.9 2014/06/01 12:49:38 thomasklausner Exp $

DISTNAME=	arxiv2bib-1.0.5
CPKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/arxiv2bib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://nathan11g.github.com/arxiv2bib
COMMENT=	Get arXiv.org metadata in BibTeX format
LICENSE=	2-clause-bsd

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-elementtree

.include "../../lang/python/egg.mk"
.include "../../textproc/py-elementtree/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
