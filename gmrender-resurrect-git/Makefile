# $NetBSD: Makefile,v 1.1 2013/08/28 20:03:17 thomasklausner Exp $

# version number from configure.ac
DISTNAME=		gmrender-resurrect-0.0.7
CATEGORIES=		net audio
MASTER_SITES=		https://github.com/hzeller/gmrender-resurrect

MAINTAINER=		rhialto@falu.nl
HOMEPAGE=		https://github.com/hzeller/gmrender-resurrect
COMMENT=		Resource efficient UPnP/DLNA renderer
LICENSE=		gnu-gpl-v2

GIT_REPOSITORIES=		gmrender-resurrect
GIT_REPO.gmrender-resurrect= 	git://github.com/hzeller/gmrender-resurrect.git

# not really hard depends, but without most of them, it's useless
DEPENDS+=		gst-plugins1-bad-[0-9]*:../../multimedia/gst-plugins1-bad
DEPENDS+=		gst-plugins1-base-[0-9]*:../../multimedia/gst-plugins1-base
DEPENDS+=		gst-plugins1-flac-[0-9]*:../../audio/gst-plugins1-flac
DEPENDS+=		gst-plugins1-good-[0-9]*:../../multimedia/gst-plugins1-good
DEPENDS+=		gst-plugins1-mpg123-[0-9]*:../../audio/gst-plugins1-mpg123
DEPENDS+=		gst-plugins1-ogg-[0-9]*:../../multimedia/gst-plugins1-ogg
DEPENDS+=		gst-plugins1-oss-[0-9]*:../../audio/gst-plugins1-oss
DEPENDS+=		gst-plugins1-soup-[0-9]*:../../net/gst-plugins1-soup
DEPENDS+=		gst-plugins1-ugly-[0-9]*:../../multimedia/gst-plugins1-ugly
DEPENDS+=		gst-plugins1-vorbis-[0-9]*:../../audio/gst-plugins1-vorbis

WRKSRC=			${WRKDIR}/gmrender-resurrect
GNU_CONFIGURE=		YES
USE_TOOLS+=		autoconf automake autoreconf pkg-config

EGDIR=			share/examples/gmrender-resurrect
INSTALLATION_DIRS=	${EGDIR}

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

post-install:
	${INSTALL_DATA} ${WRKSRC}/scripts/init.d/gmediarenderer ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../net/libupnp/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
