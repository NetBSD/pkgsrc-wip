# $NetBSD: Makefile,v 1.1.1.1 2008/01/23 08:03:35 obache Exp $
#

DISTNAME=		xlrd-0.6.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel python
MASTER_SITES=		http://www.lexicon.net/sjmachin/ \
			http://cheeseshop.python.org/packages/source/x/xlrd/
EXTRACT_SUFX=		.zip

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://www.lexicon.net/sjmachin/xlrd.htm
COMMENT=		Python library to extract data from Microsoft Excel spread sheet files

PYTHON_VERSIONS_ACCEPTED=	24 23 22 21
PYDISTUTILSPKG=		yes
PYSETUPINSTALLARGS=	-q bdist_egg

post-install:
	chmod go-w ${PREFIX}/bin/runxlrd.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
