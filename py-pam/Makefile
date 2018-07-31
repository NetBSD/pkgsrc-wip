# $NetBSD: Makefile,v 1.1 2015/02/19 21:21:12 jihbed Exp $

DISTNAME=	python-pam-1.8.3
PKGNAME=	${PYPKGPREFIX}-pam-1.8.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=FireFighterBlu3/}
GITHUB_PROJECT=	python-pam
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/FireFighterBlu3/python-pam
COMMENT=	Python PAM library
LICENSE=	mit

PY_PATCHPLIST=	yes

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
