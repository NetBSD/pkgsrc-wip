# $NetBSD: Makefile,v 1.1.1.1 2003/04/06 21:40:33 cubidou Exp $
#

DISTNAME=	PyOpenGL-2.0.0.44
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^Py//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyopengl/}

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://pyopengl.sourceforge.net/
COMMENT=	Pyhton bindings for OpenGL

USE_X11=	YES
USE_BUILDLINK2=	YES
PYDISTUTILSPKG=	YES
PY_PATCH_PLIST=	YES

post-extract:
	${CP} ${WRKSRC}/config/freebsd.cfg ${WRKSRC}/config/netbsd1.cfg.tmp

pre-build:
	${SED} -e s,@INCLUDE@,${BUILDLINK_DIR}/include,	\
	    -e s,@LIB@,${BUILDLINK_DIR}/lib,		\
	    ${WRKSRC}/config/netbsd1.cfg.tmp > ${WRKSRC}/config/netbsd1.cfg

.include "../../lang/python/extension.mk"
.include "../../graphics/Mesa/buildlink2.mk"
.include "../../math/py-Numeric/buildlink2.mk"
.include "../../x11/py-Tk/buildlink2.mk"
.include "../../lang/tcl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
