# $NetBSD$

.include "Makefile.common"

COMMENT=		Distributed signal mapping framework

CONFIGURE_ARGS+=	--disable-swig

PKGCONFIG_OVERRIDE+=	libmapper.pc.in

.include "../../audio/liblo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
