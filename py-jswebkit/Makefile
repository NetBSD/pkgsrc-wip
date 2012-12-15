# $NetBSD: Makefile,v 1.5 2012/12/15 08:27:24 asau Exp $
#

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

BUILDLINK_API_DEPENDS.pycython+= ${PYPKGPREFIX}-cython>=0.13
.include "../../devel/py-cython/buildlink3.mk"
.include "../../wip/py-webkit/buildlink3.mk"

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
