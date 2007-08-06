# $NetBSD: Makefile,v 1.6 2007/08/06 17:08:45 bsadewitz Exp $
#

DISTNAME=	pixman-0.9.0-3.20070724.fc8.src.rpm
PKGNAME=	pixman-0.9.3
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://koji.fedoraproject.org/packages/pixman/0.9.0/3.20070724.fc8/src/
EXTRACT_SUFX=	# empty


MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular X.org pixman library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++

RPM2PKG_STRIP=		0
RPM2PKG_PLIST=		# empty

BUILD_DEPENDS+=		xorg-util-macros-[0-9]*:../../devel/xorg-util-macros

USE_TOOLS+=		gmake automake pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	pixman.pc.in
PKGCONFIG_OVERRIDE+=	libcomp.pc


WRKSRC=			${WRKDIR}/pixman

post-extract:
	cd ${WRKDIR} && ${EXTRACT_CMD} ${PKGBASE}-*.bz2
pre-configure:
	cd ${WRKSRC} && autoreconf --install -v

.include "../../mk/emulator/pkg-rpm.mk"

.include "../../mk/bsd.pkg.mk"
