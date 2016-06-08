# $NetBSD: Makefile,v 1.1 2015/08/05 20:58:14 jihbed Exp $

DISTNAME=	rdopkg-0.29
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rdopkg/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/redhat-openstack/rdopkg
COMMENT=	RDO packaging utility
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	# none


DEPENDS+=	${PYPKGPREFIX}-requests>=2.5.0:../../devel/py-requests
.include "../../lang/python/egg.mk"
DEPENDS+=	${PYPKGPREFIX}-paramiko>=1.15.2:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-blessings>=1.6:../../wip/py-blessings
#DEPENDS+=	${PYPKGPREFIX}-rdoupdate>=0.13.1:../../wip/py-rdoupdate
.include "../../mk/bsd.pkg.mk"
