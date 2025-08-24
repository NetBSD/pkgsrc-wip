# $NetBSD: options.mk,v 1.9 2023/08/29 14:43:01 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.clamav
PKG_SUPPORTED_OPTIONS=	clamav-milter clamav-experimental clamav-unit-test

PKG_OPTIONS_LEGACY_OPTS+=	unit-test:clamav-unit-test
PKG_OPTIONS_LEGACY_OPTS+=	milter:clamav-milter

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	milter

.if ${PKG_OPTIONS:Mclamav-milter}
# force use of pkgsrc version of libmilter -- clamav uses the sendmail binary
# to check API compatibility(!), so it must build with as new a version of
# libmilter as pkgsrc is capable of providing
USE_BUILTIN.libmilter=	no
.  include "../../mail/libmilter/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DENABLE_MILTER=on
PLIST.milter=		yes
CONF_SAMPLES+=		clamav-milter.conf
SMF_INSTANCES+=		clamav-milter
RCD_SCRIPTS+=		clamav-milter
.endif

.if ${PKG_OPTIONS:Mclamav-experimental}
CMAKE_CONFIGURE_ARGS+=	-DENABLE_EXPERIMENTAL=on
.endif

# Enable unit test
.if ${PKG_OPTIONS:Mclamav-unit-test}
CMAKE_CONFIGURE_ARGS+=	-DENABLE_TESTS=on
TEST_TARGET=			check
# unit test's Makefile depends on gmake.
BUILDLINK_DEPMETHOD.check=	build
.  include "../../devel/check/buildlink3.mk"
.endif
