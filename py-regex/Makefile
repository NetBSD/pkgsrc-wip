# $NetBSD: Makefile,v 1.4 2014/01/17 20:21:14 jihbed Exp $

DISTNAME=	regex-2014.01.10
PKGNAME=	${PYPKGPREFIX}-regex-20140110
CATEGORIES=	textproc
MASTER_SITES=	https://pypi.python.org/packages/source/r/regex/
FETCH_USING=	curl

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://code.google.com/p/mrab-regex-hg
COMMENT=	Alternative regular expression module, to replace re
LICENSE=	python-software-foundation


PYTHON_VERSIONS_INCLUDE_3X=yes
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
