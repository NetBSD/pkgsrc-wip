# $NetBSD: options.mk,v 1.2 2009/12/25 04:59:56 schnoebe Exp $

PKG_OPTIONS_VAR=    		PKG_OPTIONS.spectrum
PKG_OPTIONS_REQUIRED_GROUPS=	storage debug
PKG_OPTIONS_GROUP.storage=	storage-mysql storage-sqlite
PKG_OPTIONS_GROUP.debug=	debug

PKG_SUGGESTED_OPTIONS=		storage-sqlite

.include "../../mk/bsd.options.mk"

PLIST_VARS+=			sqlite mysql

.if !empty(PKG_OPTIONS:Mstorage-sqlite)
. include "../../wip/poco-data-sqlite/buildlink3.mk"
PLIST.sqlite=	yes
.endif

.if !empty(PKG_OPTIONS:Mstorage-mysql)
. include "../../wip/poco-data-mysql/buildlink3.mk"
PLIST.mysql=	yes
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug
. include "../../devel/cppunit/buildlink3.mk"
.endif
