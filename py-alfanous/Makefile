# $NetBSD: Makefile,v 1.1 2015/06/30 22:02:13 jihbed Exp $

DISTNAME=	alfanous-0.7.28
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/alfanous/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.alfanous.org/
COMMENT=	Quranic search engine API
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.0.2:../../devel/py-pyparsing

WRKSRC=		${WRKDIR}/alfanous-0.7.28

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
