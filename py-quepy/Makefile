# $NetBSD: Makefile,v 1.1 2013/09/10 23:29:24 jihbed Exp $

DISTNAME=	quepy-0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=q/quepy/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/machinalis/quepy
COMMENT=	Framework to convert natural language to database queries
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/quepy-0.2

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
DEPENDS+=     ${PYPKGPREFIX}-nltk>=3.0a2:../../wip/py-nltk
.include "../../mk/bsd.pkg.mk"
