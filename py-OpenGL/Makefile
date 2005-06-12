# $NetBSD: Makefile,v 1.5 2005/06/12 23:51:26 kristerw Exp $
#

DISTNAME=	PyOpenGL-2.0.0.44
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^Py//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyopengl/}

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://pyopengl.sourceforge.net/
COMMENT=	Pyhton bindings for OpenGL

PYDISTUTILSPKG=	YES
PY_PATCHPLIST=	YES

post-extract:
	${CP} ${WRKSRC}/config/freebsd.cfg ${WRKSRC}/config/netbsd1.cfg.tmp

pre-build:
	${SED} -e s,@INCLUDE@,${BUILDLINK_DIR}/include,	\
	    -e s,@LIB@,${BUILDLINK_DIR}/lib,		\
	    ${WRKSRC}/config/netbsd1.cfg.tmp > ${WRKSRC}/config/netbsd1.cfg

.include "../../lang/python/extension.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
