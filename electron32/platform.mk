# $NetBSD$
#
# NODE_GYP
#	Absolute path for node-gyp.
#

ELECTRON_VER=		32.3.2
ELECTRON_MAJOR=		${ELECTRON_VER:tu:C/\\.[[:digit:]\.]*//}
NODE_VERSION_DEFAULT=	20
ELECTRON=		electron${ELECTRON_MAJOR}

# Package-settable variable
# Values:
# - "bundled" if the package bundles electron libraries
# - "dependency" if the package uses electron as dependency
USE_ELECTRON?=		electronpkg

.if !empty(USE_ELECTRON:Melectronpkg) && empty(PKGBASE:M${ELECTRON})
PKG_FAIL_REASON+=	"USE_ELECTRON not defined. Should be \"bundled\" or \"dependency\"."
.elif !empty(PKGBASE:M${ELECTRON}) && empty(USE_ELECTRON:Melectronpkg)
PKG_FAIL_REASON+=	"USE_ELECTRON is defined for ${PKGBASE} package."
.endif

TOOL_DEPENDS+=		nodejs-${NODE_VERSION_DEFAULT}.*:../../lang/nodejs${NODE_VERSION_DEFAULT}
.if ${USE_ELECTRON} == "dependency"
DEPENDS+=		${ELECTRON}>=${ELECTRON_VER}:../../wip/${ELECTRON}
.elif ${USE_ELECTRON} == "bundled"
TOOL_DEPENDS+=		${ELECTRON}>=${ELECTRON_VER}:../../wip/${ELECTRON}
.endif

.include "../../mk/bsd.prefs.mk"

.for c_arch in x86_64 aarch64
ONLY_FOR_PLATFORM+=	NetBSD-1[0-9].*-${c_arch}
ONLY_FOR_PLATFORM+=	Linux-*-${c_arch}
ONLY_FOR_PLATFORM+=	Darwin-*-${c_arch}
ONLY_FOR_PLATFORM+=	FreeBSD-*-${c_arch}
.endfor

ELECTRONBIN=		${PREFIX}/lib/${ELECTRON}/electron
NODE_GYP=		${PREFIX}/lib/node_modules/npm/bin/node-gyp-bin/node-gyp

FILES_SUBST+=		ELECTRON=${ELECTRON}
FILES_SUBST+=		ELECTRONBIN=${ELECTRONBIN}

.if ${USE_ELECTRON} == "bundled" || ${USE_ELECTRON} == "electronpkg"

PLIST_VARS+=		swiftshader
.  if ${MACHINE_ARCH} == "x86_64"
PLIST.swiftshader=	yes
.  endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/speech-dispatcher/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../devel/dconf/buildlink3.mk"
.include "../../devel/libatomic/buildlink3.mk"
.include "../../devel/libepoll-shim/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/compiler-rt/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/rust/rust.mk"
.include "../../misc/usbids/buildlink3.mk"
#.include "../../mk/jpeg.buildlink3.mk" # libjpeg-turbo
.include "../../multimedia/dav1d/buildlink3.mk"
.include "../../multimedia/libaom/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../multimedia/openh264/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../print/libcups/buildlink3.mk"
.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/pciutils/buildlink3.mk"
# Use -lpciutils instead of -lpci for pkgsrc.
BUILDLINK_TRANSFORM+=	l:pci:pciutils
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../www/nghttp2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif
