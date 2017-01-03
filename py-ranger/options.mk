# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-ranger

PKG_SUPPORTED_OPTIONS+=	caca
PKG_SUPPORTED_OPTIONS+=	py-chardet
PKG_SUPPORTED_OPTIONS+=	w3m
PKG_SUPPORTED_OPTIONS+=	elinks
PKG_SUPPORTED_OPTIONS+=	lynx
PKG_SUPPORTED_OPTIONS+=	sudo
PKG_SUPPORTED_OPTIONS+=	highlight
PKG_SUPPORTED_OPTIONS+=	atool
PKG_SUPPORTED_OPTIONS+=	bsdtar
PKG_SUPPORTED_OPTIONS+=	unrar
PKG_SUPPORTED_OPTIONS+=	mediainfo
PKG_SUPPORTED_OPTIONS+=	exiftool
PKG_SUPPORTED_OPTIONS+=	poppler
PKG_SUPPORTED_OPTIONS+=	odt2txt

PLIST_VARS+=	${PKG_SUPPORTED_OPTIONS}

DEPENDS+=	coreutils-[0-9]*:../../sysutils/coreutils

.include "../../mk/bsd.options.mk"

###
### libcaca support.
###
.if !empty(PKG_OPTIONS:Mcaca)
.include "../../graphics/libcaca/buildlink3.mk"
.include "../../mk/pkg-build-options.mk"                                                                                                                                                                                                                                                                                       .if !empty(PKG_BUILD_OPTIONS.libcaca:Mimlib2)                                                                                                                                                                                                                                                                                  CONFIGURE_ARGS+=        --enable-imlib2                                                                                                                                                                                                                                                                                        .endif
.endif

###
### py-chardet support.
###
.if !empty(PKG_OPTIONS:Mpy-chardet)
DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
.endif

###
### w3m support.
###
.if !empty(PKG_OPTIONS:Mw3m)
DEPENDS+=	w3m-img-[0-9]*:../../www/w3m-img
.endif

###
### pdf2txt support.
###
.if !empty(PKG_OPTIONS:Mpoppler)
DEPENDS+=	poppler-utils-[0-9]*:../../print/poppler-utils
.endif

###
### sudo support.
###
.if !empty(PKG_OPTIONS:Msudo)
DEPENDS+=	sudo-[0-9]*:../../security/sudo
.endif

###
### lynxam support.
###
.if !empty(PKG_OPTIONS:Mlynx)
DEPENDS+=	lynx-[0-9]*:../../www/lynx
.endif

###
### mediainfo support.
###
.if !empty(PKG_OPTIONS:Mmediainfo)
DEPENDS+=	mediainfo-[0-9]*:../../multimedia/mediainfo
.endif

###
### highlight support.
###
.if !empty(PKG_OPTIONS:Mhighlight)
DEPENDS+=	highlight-[0-9]*:../../textproc/highlight
.endif

###
### atool support.
###
.if !empty(PKG_OPTIONS:Matool)
DEPENDS+=	atool-[0-9]*:../../wip/atool
.endif

###
### bsdtar support.
###
.if !empty(PKG_OPTIONS:Mbsdtar)
DEPENDS+=	bsdtar-[0-9]*:../../archivers/bsdtar
.endif

###
### unrar support.
###
.if !empty(PKG_OPTIONS:Munrar)
DEPENDS+=	unrar-[0-9]*:../../archivers/unrar
.endif

###
### elinks support.
###
.if !empty(PKG_OPTIONS:Melinks)
DEPENDS+=	elinks-[0-9]*:../../www/elinks
.endif

###
### exiftool support.
###
.if !empty(PKG_OPTIONS:Mexiftool)
DEPENDS+=	p5-Image-ExifTool-[0-9]*:../../graphics/p5-Image-ExifTool
.endif

###
### odt2txt support.
###
.if !empty(PKG_OPTIONS:Modt2txt)
DEPENDS+=	odt2txt-[0-9]*:../../converters/odt2txt
.endif
