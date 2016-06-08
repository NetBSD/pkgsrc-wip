# $NetBSD: Makefile,v 1.1 2014/03/19 21:48:53 jihbed Exp $

DISTNAME=	cmd2-0.6.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cmd2/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	${MASTER_SITE_PYPI:=c/cmd2/}
COMMENT=	Extra features for standard library's cmd module
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.0.1:../../devel/py-pyparsing

WRKSRC=		${WRKDIR}/cmd2-0.6.7

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
