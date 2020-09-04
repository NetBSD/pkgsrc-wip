# $NetBSD: Makefile,v 1.1 2015/02/19 21:21:12 jihbed Exp $

DISTNAME=	python3-xapp-2.0.1
PKGNAME=	${PYPKGPREFIX}-xapp-2.0.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=linuxmint/}
GITHUB_PROJECT=	python3-xapp
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/linuxmint/python3-xapp
COMMENT=	Python3 Xapp library
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

PY_PATCHPLIST=	yes

.include "../../lang/python/pyversion.mk"

USE_TOOLS+=	gmake pkg-config intltool msgfmt

DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil

PLIST_SUBST+=           PYSITELIB=${PYSITELIB}

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
