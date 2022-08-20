# $NetBSD: Makefile,v 1.16 2018/04/06 15:59:56 fhajny Exp $

DISTNAME=	elasticsearch-${GITHUB_RELEASE:S/v//}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=elastic/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/elastic/${GITHUB_PROJECT}/
COMMENT=	Official low-level python client for Elasticsearch
LICENSE=	apache-2.0

GITHUB_RELEASE=	v8.3.3
GITHUB_PROJECT=	elasticsearch-py

EGG_NAME=	${DISTNAME:S/-py//}

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.0.0:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-elastic-transport>=8.0.0:../../wip/py-elastic-transport
DEPENDS+=	${PYPKGPREFIX}-requests>=2.4.0:../../devel/py-requests
#DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.21.1:../../www/py-urllib3

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
