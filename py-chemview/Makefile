# $NetBSD: Makefile,v 1.1 2015/06/09 23:38:17 jihbed Exp $

DISTNAME=	chemview-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_PYPI:=c/chemview/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/gabrielelanaro/chemview
COMMENT=	Interactive molecular viewer for IPython notebook
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-ipython-[0-9]*:../../devel/py-ipython

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
