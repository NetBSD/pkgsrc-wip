# $NetBSD: Makefile,v 1.6 2015/07/13 15:11:25 thomasklausner Exp $

DISTNAME=	PythonMagick-0.9.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python graphics
MASTER_SITES=	http://www.imagemagick.org/download/python/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://www.imagemagick.org/script/api.php
COMMENT=	Python binding for ImageMagick

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

GNU_CONFIGURE=	yes
PY_PATCHPLIST=	yes

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../devel/py-boost/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
