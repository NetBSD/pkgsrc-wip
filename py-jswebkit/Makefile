# $NetBSD: Makefile,v 1.7 2014/05/09 07:38:48 thomasklausner Exp $

DISTNAME=	python-jswebkit-0.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://gwrite.googlecode.com/files/

MAINTAINER=	silasdb@gmail.com
HOMEPAGE=	http://gwrite.googlecode.com/
COMMENT=	WebKit/JavaScriptCore Python bindings
LICENSE=	gnu-lgpl-v3

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

PLIST_SUBST+=	THIS_EGG_FILE=${EGG_NAME:S|python-|python_|}-py${PYVERSSUFFIX}.egg-info

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2 via py-webkit

BUILDLINK_API_DEPENDS.pycython+= ${PYPKGPREFIX}-cython>=0.13
.include "../../devel/py-cython/buildlink3.mk"

# This most come before including wip/py-webkit/buildlink3.mk, because py-webkit
# also sets PYTHON_VERSIONS_INCOMPATIBLE.
.include "../../lang/python/distutils.mk"

.include "../../wip/py-webkit/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
