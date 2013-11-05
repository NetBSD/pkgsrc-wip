# $NetBSD: Makefile,v 1.1 2013/11/05 15:48:07 jihbed Exp $

DISTNAME=	thLib-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/t/thLib/
EXTRACT_SUFX=	.zip#md5=4539622094282799aec58c3470923e8a
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://work.thaslwanter.at/
COMMENT=	Collection of Python utilities for signal analysis

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
