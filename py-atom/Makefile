# $NetBSD: Makefile,v 1.2 2014/07/26 14:07:39 jihbed Exp $

DISTNAME=	atom-0.3.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/atom/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/nucleic/atom
COMMENT=	Memory efficient Python objects
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/atom-0.3.9

CONFLICTS+=	${PYPKGPREFIX}-gdata-[0-9]*

USE_LANGUAGES=	c c++

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
