# $NetBSD: options.mk,v 1.1 2009/10/06 09:09:00 fhajny Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libmemcached
PKG_SUPPORTED_OPTIONS=		dtrace
PKG_SUGGESTED_OPTIONS=          # empty

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdtrace)
CONFIGURE_ARGS+=	--enable-dtrace

# Ditto as in Makefile, force dtrace to match pkgsrc's ABI
. if ${ABI} != 64
SUBST_CLASSES+=		dtrace
SUBST_STAGE.dtrace=	post-configure
SUBST_MESSAGE.dtrace=	Fixing dtrace for ABI=32
SUBST_FILES.dtrace=	libmemcached/Makefile
SUBST_SED.dtrace=	-e '/DTRACEFLAGS =/s/-64//'
. endif

.endif
