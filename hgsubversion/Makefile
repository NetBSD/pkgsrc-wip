# $NetBSD: Makefile,v 1.4 2015/06/09 11:14:45 thomasklausner Exp $

DISTNAME=		1.8.1
PKGNAME=		${PYPKGPREFIX}-hgsubversion-${DISTNAME}
CATEGORIES=		devel python
MASTER_SITES=		https://bitbucket.org/durin42/hgsubversion/get/

MAINTAINER=		ura@jp.NetBSD.org
HOMEPAGE=		http://bitbucket.org/durin42/hgsubversion/
COMMENT=		Subversion plugin for Mercurial
LICENSE=		gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-mercurial>=2.0:../../devel/py-mercurial
DEPENDS+=	${PYPKGPREFIX}-subvertpy>=0.7.4:../../devel/py-subvertpy

DIST_SUBDIR=	hgsubversion
WRKSRC=		${WRKDIR}/durin42-hgsubversion-dde1ade36a49

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-mercurial
EGG_NAME=		hgsubversion-${DISTNAME}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
