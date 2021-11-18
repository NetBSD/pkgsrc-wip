# $NetBSD: Makefile,v 1.2 2020/03/08 16:50:41 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-base/-opengl/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - OpenGL plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	gl

LDFLAGS+=		${COMPILER_RPATH_FLAG}${X11BASE}/lib -L${X11BASE}/lib

# ext/gl/meson.build:57:20: ERROR: Unknown variable "gstgl_dep".

.include "../../multimedia/gst-plugins1-base/Makefile.common"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
