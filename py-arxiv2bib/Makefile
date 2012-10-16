# $NetBSD: Makefile,v 1.4 2012/10/16 09:26:16 jihbed Exp $
#

DISTNAME=	arxiv2bib-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	http://pypi.python.org/packages/source/a/arxiv2bib/
EXTRACT_USING=	gtar

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://nathan11g.github.com/arxiv2bib
COMMENT=	Get arXiv.org metadata in BibTeX format
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/arxiv2bib-1.0.0

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE= 26
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../textproc/py-elementtree/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
