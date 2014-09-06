# $NetBSD: Makefile,v 1.2 2014/09/06 09:52:03 makoto Exp $

META_PACKAGE=	yes

.include	"../../wip/gnuradio/Makefile.version"

DISTNAME=       gnuradio-${VERSION}
CATEGORIES=	meta-pkgs ham
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gnuradio/
COMMENT=	"meta-package" for GNU Radio

.include "options.mk"

DEPENDS+=	gnuradio-core-${VERSION}{,nb[0-9]*}:../../wip/gnuradio-core
#DEPENDS+=	gnuradio-core-docs-${VERSION}{,nb[0-9]*}:../../wip/gnuradio-core-docs
DEPENDS+=	gnuradio-audio-jack-${VERSION}{,nb[0-9]*}:../../wip/gnuradio-audio-jack
DEPENDS+=	gnuradio-audio-oss-${VERSION}{,nb[0-9]*}:../../wip/gnuradio-audio-oss
DEPENDS+=	gnuradio-audio-portaudio-${VERSION}{,nb[0-9]*}:../../wip/gnuradio-audio-portaudio
DEPENDS+=	gnuradio-gsm-${VERSION}{,nb[0-9]*}:../../wip/gnuradio-gsm
DEPENDS+=	usrp-${VERSION}{,nb[0-9]*}:../../wip/usrp
DEPENDS+=	usrp-docs-${VERSION}{,nb[0-9]*}:../../wip/usrp-docs
DEPENDS+=	gnuradio-usrp-${VERSION}{,nb[0-9]*}:../../wip/gnuradio-usrp
DEPENDS+=	gnuradio-wxgui-${VERSION}{,nb[0-9]*}:../../wip/gnuradio-wxgui
DEPENDS+=	gnuradio-examples-${VERSION}{,nb[0-9]*}:../../wip/gnuradio-examples
DEPENDS+=	gnuradio-video-sdl-${VERSION}{,nb[0-9]*}:../../wip/gnuradio-video-sdl
DEPENDS+=	gnuradio-trellis-${VERSION}{,nb[0-9]*}:../../wip/gnuradio-trellis
.if !empty(PKG_OPTIONS:Mgnuradio-radio-astronomy)
# Omit gnuradio-radio-astronomy because it has a RESTRICTED dependency.
DEPENDS+=	gnuradio-radio-astronomy-${VERSION}{,nb[0-9]*}:../../wip/gnuradio-radio-astronomy
.endif
DEPENDS+=	gnuradio-howto-${VERSION}{,nb[0-9]*}:../../wip/gnuradio-howto

.include "../../mk/bsd.pkg.mk"
