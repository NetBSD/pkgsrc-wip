# $NetBSD: Makefile,v 1.1 2014/06/22 22:17:15 jihbed Exp $

DISTNAME=	atom-0.3.9
PKGNAME=    ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/a/atom/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/nucleic/atom
COMMENT=	Memory efficient Python objects
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/atom-0.3.9

USE_LANGUAGES=	c c++

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
