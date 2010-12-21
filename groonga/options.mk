# $NetBSD: options.mk,v 1.3 2010/12/21 11:35:40 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.groonga
PKG_SUPPORTED_OPTIONS=	mecab tests zlib lzo
PKG_SUGGESTED_OPTIONS=  mecab tests

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		mecab

.if !empty(PKG_OPTIONS:Mmecab)
CONFIGURE_ARGS+=	--with-mecab
CONFIGURE_ARGS+=	--with-mecab-config=${BUILDLINK_PREFIX.mecab}/bin/mecab-config
.include "../../textproc/mecab/buildlink3.mk"
PLIST.mecab=		yes
.else
CONFIGURE_ARGS+=	--without-mecab
.endif

.if !empty(PKG_OPTIONS:Mtests)
CONFIGURE_ARGS+=	--with-ruby=${RUBY}
CONFIGURE_ARGS+=	--with-cutter
USE_TOOLS+=		gmake
TEST_TARGET=		check
BUILDLINK_DEPMETHOD.${RUBY_BASE}+=	build
.include "../../lang/ruby/buildlink3.mk"
.include "../../devel/cutter/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ruby
CONFIGURE_ARGS+=	--without-cutter
.endif

.if !empty(PKG_OPTIONS:Mzlib)
CONFIGURE_ARGS+=	--with-zlib
.include "../../devel/zlib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-zlib
.endif

.if !empty(PKG_OPTIONS:Mlzo)
CONFIGURE_ARGS+=	--with-lzo
.include "../../archivers/lzo/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-lzo
.endif
