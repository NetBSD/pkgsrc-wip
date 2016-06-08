# $NetBSD: Makefile,v 1.1 2014/07/26 14:41:51 jihbed Exp $

DISTNAME=	cubicweb-3.19.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cubicweb/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.cubicweb.org/
COMMENT=	Repository of entities / relations for knowledge management
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2


DEPENDS+=	${PYPKGPREFIX}-passlib>=1.6.2../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.3.5:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-rql>=0.33.0:../../wip/py-rql
DEPENDS+=	${PYPKGPREFIX}-logilab-common-[0-9]*:../../devel/py-logilab-common

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
