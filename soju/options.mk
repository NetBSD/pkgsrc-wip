# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.soju
PKG_OPTIONS_OPTIONAL_GROUPS=	sqlite3
PKG_OPTIONS_GROUP.sqlite3=	moderncsqlite
PKG_SUPPORTED_OPTIONS=		# blank
PKG_SUGGESTED_OPTIONS=		# blank

.include "../../mk/bsd.options.mk"

# Use an alternative SQLite library that does not require CGO
.if !empty (PKG_OPTIONS:Mmoderncsqlite)
GO_BUILD_PATTERN+=	-tags=moderncsqlite
.endif

## Link with the system libsqlite3
#.if !empty (PKG_OPTIONS:Mlibsqlite3)
#GO_BUILD_PATTERN+=	-tags=libsqlite3
#.include "../../databases/sqlite3/buildlink3.mk"
#.endif

## Build with PAM authentication support
#.if !empty (PKG_OPTIONS:Mpam)
#GO_BUILD_PATTERN+=	-tags=pam
#.endif
