# $NetBSD: Makefile,v 1.1 2015/02/19 21:21:12 jihbed Exp $

DISTNAME=	python-xapp-1.4.0
PKGNAME=	${PYPKGPREFIX}-xapp-1.4.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=linuxmint/}
GITHUB_PROJECT=	python-xapp
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/linuxmint/python-xapp
COMMENT=	Python Xapp library
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

PY_PATCHPLIST=	yes

.include "../../lang/python/pyversion.mk"

USE_TOOLS+=	gmake pkg-config intltool msgfmt

DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
