# $NetBSD: Makefile,v 1.3 2012/10/19 18:16:48 silasdb Exp $
#

DISTNAME=	python-jswebkit-0.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://gwrite.googlecode.com/files/

MAINTAINER=	silasdb@gmail.com
HOMEPAGE=	http://gwrite.googlecode.com/
COMMENT=	WebKit/JavaScriptCore Python bindings
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

BUILDLINK_API_DEPENDS.pycython+= ${PYPKGPREFIX}-cython>=0.13
.include "../../devel/py-cython/buildlink3.mk"
.include "../../wip/py-webkit/buildlink3.mk"

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
