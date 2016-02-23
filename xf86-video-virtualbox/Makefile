# $NetBSD: Makefile,v 1.1 2015/09/15 20:56:03 tnn2 Exp $

DISTNAME=	VirtualBox-5.0.14
PKGNAME=	${DISTNAME:S/VirtualBox/xf86-video-virtualbox/}
CATEGORIES=	x11
MASTER_SITES=	http://download.virtualbox.org/virtualbox/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.virtualbox.org/
COMMENT=	Modular Xorg Virtualbox video driver
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config autoconf automake autoreconf

VBOXVIDEO_DIR=	src/VBox/Additions/x11/vboxvideo
CONFIGURE_DIRS=	${VBOXVIDEO_DIR}

CHECK_PORTABILITY_SKIP=	*	# don't care

post-extract:
.for f in configure.ac Makefile.am
	cp ${FILESDIR}/${f} ${WRKSRC}/${VBOXVIDEO_DIR}
.endfor

pre-configure:
	cd ${WRKSRC}/${VBOXVIDEO_DIR} && autoreconf -vif

.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXext?=   build
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xineramaproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
