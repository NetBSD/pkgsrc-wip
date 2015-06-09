# $NetBSD: Makefile,v 1.3 2015/06/09 08:19:23 thomasklausner Exp $

DISTNAME=		1.8.1
PKGNAME=		hgsubversion-${DISTNAME}
CATEGORIES=		devel python
MASTER_SITES=		https://bitbucket.org/durin42/hgsubversion/get/

MAINTAINER=		ura@jp.NetBSD.org
HOMEPAGE=		http://bitbucket.org/durin42/hgsubversion/
COMMENT=		Subversion plugin for Mercurial
LICENSE=		gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-mercurial>=2.0:../../devel/py-mercurial
DEPENDS+=	${PYPKGPREFIX}-subvertpy>=0.7.4:../../devel/py-subvertpy

DIST_SUBDIR=    hgsubversion
WRKSRC=		${WRKDIR}/durin42-hgsubversion-dde1ade36a49

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-mercurial
EGG_NAME=		hgsubversion-${DISTNAME}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
