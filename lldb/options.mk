# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.lldb

PKG_SUPPORTED_OPTIONS+=	tests curses
PKG_SUGGESTED_OPTIONS=	curses

.include "../../mk/bsd.options.mk"

.if ${PKG_OPTIONS:Mtests}
CMAKE_ARGS+=	-DLLVM_INCLUDE_TESTS=ON
.else
# py-lit, py-psutil, lld
CMAKE_ARGS+=	-DLLVM_INCLUDE_TESTS=OFF
.endif

.if ${PKG_OPTIONS:Mcurses}
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"

.  if ${OPSYS} == "NetBSD"
.    if exists(/usr/include/panel.h)
CMAKE_ARGS+=	LLDB_ENABLE_CURSES=1
.    else
.include "../../devel/ncurses/buildlink3.mk"
.      if exists(${BUILDLINK_PREFIX.ncurses}/include/panel.h)
CMAKE_ARGS+=    LLDB_ENABLE_CURSES=1
.      else
CMAKE_ARGS+=    LLDB_ENABLE_CURSES=0
.      endif
.    endif
CMAKE_ARGS+=	LLDB_ENABLE_CURSES=0
.  endif

.  if ${OPSYS} != "NetBSD"
.include "../../devel/ncurses/buildlink3.mk"
.    if exists(${BUILDLINK_PREFIX.ncurses}/include/panel.h)
CMAKE_ARGS+=    LLDB_ENABLE_CURSES=1
.    else
CMAKE_ARGS+=    LLDB_ENABLE_CURSES=0
.    endif
.  endif

.else

CMAKE_ARGS+=	LLDB_ENABLE_CURSES=0
.endif
