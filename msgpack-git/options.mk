# $NetBSD: options.mk,v 1.1 2014/11/22 22:43:43 jonthn Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.msgpack
PKG_SUPPORTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
BUILDLINK_DEPMETHOD.googletest+=	build
.include "../../devel/googletest/buildlink3.mk"
TEST_TARGET=	check
CMAKE_ARGS+=	-DMSGPACK_BUILD_TESTS=ON
.endif
