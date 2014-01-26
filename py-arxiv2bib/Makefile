# $NetBSD: Makefile,v 1.7 2014/01/26 15:49:52 thomasklausner Exp $

DISTNAME=	arxiv2bib-1.0.5
CPKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	https://pypi.python.org/packages/source/a/arxiv2bib/
EXTRACT_SUFX=	.zip
FETCH_USING=	curl

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://nathan11g.github.com/arxiv2bib
COMMENT=	Get arXiv.org metadata in BibTeX format
LICENSE=	2-clause-bsd

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-elementtree

.include "../../lang/python/egg.mk"
.include "../../textproc/py-elementtree/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
