# $NetBSD: Makefile,v 1.5 2015/08/10 22:35:55 jihbed Exp $

DISTNAME=	lea-2.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lea/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://bitbucket.org/piedenis/lea
COMMENT=	Discrete probability distributions in Python
LICENSE=	gnu-lgpl-v3 AND gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline

WRKSRC=		${WRKDIR}/lea-2.1.2

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
