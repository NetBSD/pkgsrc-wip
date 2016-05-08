# $NetBSD$

DISTNAME=	xcb-util-xrm-1.0
CATEGORIES=	x11
EXTRACT_SUFX=	.tar.bz2

GIT_REPOSITORIES=	xcb-util-xrm
GIT_REPO.xcb-util-xrm=	https://github.com/Airblader/xcb-util-xrm.git
WRKSRC=			${WRKDIR}/xcb-util-xrm

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Airblader/xcb-util-xrm/
COMMENT=	XCB utility functions for the X resource manager
LICENSE=	x11

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf automake pkg-config

PKGCONFIG_OVERRIDE=	xcb-xrm.pc.in
#PKGCONFIG_OVERRIDE+=	xcb_xrm_intro.in

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

.include "../../x11/xcb-util/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
