# $NetBSD: Makefile,v 1.1 2012/10/19 16:52:29 silasdb Exp $
#

DISTNAME=	python-jswebkit-0.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://gwrite.googlecode.com/files/

MAINTAINER=	silasdb@gmail.com
HOMEPAGE=	http://gwrite.googlecode.com/
COMMENT=	WebKit/JavaScriptCore Python bindings
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

BUILDLINK_API_DEPENDS.pycython+= ${PYPKGPREFIX}-cython>=0.13
.include "../../devel/py-cython/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
