# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:38 thomasklausner Exp $

DISTNAME=	bibtexparser-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	https://pypi.python.org/packages/source/b/bibtexparser/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/sciunto/python-bibtexparser
COMMENT=	Bibtex parser for python3
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	26 27

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
