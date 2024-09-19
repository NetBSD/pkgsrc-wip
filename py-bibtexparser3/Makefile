# $NetBSD: Makefile,v 1.3 2015/04/13 23:22:02 othyro Exp $

DISTNAME=	bibtexparser-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bibtexparser/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/sciunto/python-bibtexparser
COMMENT=	Bibtex parser for python3
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
