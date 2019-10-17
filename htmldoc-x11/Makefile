# $NetBSD$

PKGNAME=	htmldoc-x11-${VERSION}

CONFIGURE_ARGS+=	--with-gui

# FLTK version 1.4 is supported too
#.include "../../x11/fltk13/buildlink3.mk"
.include "../../wip/fltk14-devel/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../wip/htmldoc/Makefile.common"
.include "../../mk/bsd.pkg.mk"
