# $NetBSD: Makefile,v 1.1 2014/12/26 15:39:45 nros Exp $

.include "Makefile.common"

COMMENT=

CONFIGURE_ARGS+=	--with-modules=gdome_cpp_smart
PKGCONFIG_OVERRIDE+=	gdome2-cpp-smart.pc.in

.include "../../textproc/gdome2/buildlink3.mk"
BUILDLINK_DEPMETHOD.libxslt=  build
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
