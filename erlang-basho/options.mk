# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.erlang
PKG_SUPPORTED_OPTIONS=	# empty
PKG_SUGGESTED_OPTIONS=	# empty

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Darwin" || ${OPSYS} == "FreeBSD" || \
    ${OPSYS} == "Linux"
PKG_SUPPORTED_OPTIONS+=	dtrace
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dtrace

.if !empty(PKG_OPTIONS:Mdtrace)
.  if ${OPSYS} == "SunOS" || ${OPSYS} == "Darwin" || ${OPSYS} == "FreeBSD"
CONFIGURE_ARGS+=	--with-dynamic-trace=dtrace
.  elif ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-dynamic-trace=systemtap
.  endif
PLIST.dtrace=		yes
.endif

# Help generate optional PLIST parts:
PRINT_PLIST_AWK+=	{if ($$0 ~ /dtrace_user/) {$$0 = "$${PLIST.dtrace}" $$0;}}
