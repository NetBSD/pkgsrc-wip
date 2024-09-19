# $NetBSD$

GITHUB_PROJECT=	budgie-screensaver
GITHUB_TAG=	v5.0.2
DISTNAME=	v5.0.2
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=BuddiesOfBudgie/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/BuddiesOfBudgie/budgie-screensaver/
COMMENT=	Requirement for budgie desktop
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config intltool automake autoconf autoreconf autoupdate m4
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

WRKSRC=			${WRKDIR}/budgie-screensaver-5.0.2
USE_PKGLOCALEDIR=	yes

#pre-configure:
#	cd ${WRKSRC} && autoreconf -fiv


.include "../../devel/meson/build.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gnome-desktop3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
