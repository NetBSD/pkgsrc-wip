# $NetBSD: Makefile,v 1.5 2013/12/06 00:27:44 jihbed Exp $

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

PYTHON_VERSIONS_INCLUDE_3X= yes 

PYDISTUTILSPKG=	yes

.include "../../lang/python/egg.mk"
.include "../../textproc/py-elementtree/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
