# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:47 thomasklausner Exp $

DISTNAME=	thLib-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/thLib/}
EXTRACT_SUFX=	.zip#md5=4539622094282799aec58c3470923e8a

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://work.thaslwanter.at/
COMMENT=	Collection of Python utilities for signal analysis

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
