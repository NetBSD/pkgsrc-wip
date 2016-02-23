# $NetBSD: Makefile,v 1.1 2015/09/15 20:56:51 tnn2 Exp $

DISTNAME=	VirtualBox-5.0.14
PKGNAME=	${DISTNAME:S/VirtualBox/xf86-input-vboxmouse/}
CATEGORIES=	x11
MASTER_SITES=	http://download.virtualbox.org/virtualbox/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.virtualbox.org/
COMMENT=	Modular Xorg Virtualbox mouse driver
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config autoconf automake autoreconf

VBOXMOUSE_DIR=	src/VBox/Additions/x11/vboxmouse
CONFIGURE_DIRS=	${VBOXMOUSE_DIR}

CHECK_PORTABILITY_SKIP=	*	# don't care

post-extract:
.for f in configure.ac Makefile.am
	cp ${FILESDIR}/${f} ${WRKSRC}/${VBOXMOUSE_DIR}
.endfor

pre-configure:
	cd ${WRKSRC}/${VBOXMOUSE_DIR} && autoreconf -vif

.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/inputproto/buildlink3.mk"
.include "../../x11/kbproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
