# $NetBSD: options.mk,v 1.4 2013/04/07 09:49:43 makoto Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pulseaudio
PKG_SUPPORTED_OPTIONS=	avahi x11
PKG_SUGGESTED_OPTIONS=	avahi x11
PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

## The option x11 in X11_TYPE=native with NetBSD 5.x will install
## modular xorg libraries (X11 and X11-xcb). Please drop option x11
## with following line if this matters.
## PKG_OPTION.pulseaudio+ = -x11

.include "../../mk/bsd.options.mk"

###
### avahi
###
.if !empty(PKG_OPTIONS:Mavahi)
.include "../../net/avahi/buildlink3.mk"
PLIST.avahi=		yes
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif

###
### X11
###
.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
# Simply including following file won't buildlink x11-xcb related files.
# See the tweak below for post-wrapper target.
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.if ${OPSYS} == "NetBSD"
. if !empty(OS_VERSION:M5.*)
.  if ${X11_TYPE} != "modular"
.include "../../x11/libxcb/buildlink3.mk"
LDFLAGS+=	-L ${PREFIX}/lib -lX11-xcb -lX11
post-wrapper:
##--------- fragment from mk/buildlink3/bsd.buildlink3.mk
# case ${BUILDLINK_PREFIX.${_pkg_}} in                            \
#        ${LOCALBASE})   buildlink_dir="${BUILDLINK_DIR}" ;;             \
#        ${X11BASE})     buildlink_dir="${BUILDLINK_X11_DIR}" ;;         \
#        *)              buildlink_dir="${BUILDLINK_DIR}" ;;             \
#        esac;                                                           \
#	src="${_CROSS_DESTDIR}${BUILDLINK_PREFIX.${_pkg_}}/x11-xcb";	\
#	dest="$$buildlink_dir/x11-xcb";
	src="${PREFIX}/lib/pkgconfig/x11-xcb.pc";\
	dest="${BUILDLINK_DIR}/lib/pkgconfig";	\
	${LN} -s $$src $$dest;			\
#
	src="${PREFIX}/include/X11/Xlib-xcb.h";	\
	dest="${BUILDLINK_DIR}/include/X11/";	\
	${LN} -s $$src $$dest	; 		\
#
	for i in ${PREFIX}/lib/libX11-xcb* ;	\
	  do					\
	    src="$$i";				\
	    dest="${BUILDLINK_DIR}/lib/";	\
	    ${LN} -s $$src $$dest ;		\
	done;					\
# Missing _XGetRequest in libX11.so.6 in (native) x11-links
	for i in ${PREFIX}/lib/libX11\.* ;	\
	  do					\
	    src="$$i";				\
	    dest="${BUILDLINK_DIR}/lib/";	\
	    ${LN} -sf $$src $$dest ;		\
	done;
	# Last chunck replaces x11-links stuff
.  endif
. endif
.endif
##---------

PLIST.x11=		yes
.else
CONFIGURE_ARGS+=	--disable-x11
.endif
