# $NetBSD$
# Local variables:
# coding: unix
# End:
DISTNAME=		suricata-8.0.1
PKGREVISION=		1
CATEGORIES=		net security
MASTER_SITES=		https://www.openinfosecfoundation.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://suricata.io/
COMMENT=		Fast open source network analysis and threat detection software
LICENSE=		gnu-gpl-v2

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

#PKGCONFIG_OVERRIDE+=	rust/vendor/libz-sys/src/zlib-ng/zlib.pc.in
#PKGCONFIG_OVERRIDE+=	rust/vendor/libz-sys/src/zlib/zlib.pc.in

USE_LANGUAGES=		c c++

LIBS.NetBSD+=		 -lm

PKG_OPTIONS_VAR=	PKG_OPTIONS.suricata
PKG_SUPPORTED_OPTIONS=	enable-unittests enable-debug enable-profiling
#PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Menable-unittests)
CONFIGURE_ARGS+=	--enable-unittests
.endif

.if !empty(PKG_OPTIONS:Menable-debug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Menable-profiling)
CONFIGURE_ARGS+=	--enable-profiling
.endif

.include "../../devel/pcre2/buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"

# not found by configure for some reason:
.include "../../lang/libunwind/buildlink3.mk"

.include "../../archivers/lz4/buildlink3.mk"
.include "../../lang/rust/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
