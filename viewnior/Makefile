# $NetBSD: Makefile,v 1.20 2015/09/12 20:03:01 tnn Exp $
#

DISTNAME=	viewnior-1.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=xsisqox/}
GITHUB_PROJECT=	Viewnior
GITHUB_TAG=	viewnior-${PKGVERSION_NOREV}
# For some reason the initial 'v' of the tag is dropped.
# Perhaps it is supposed to handle tags similar to 'v0.0'.
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://siyanpanayotov.com/project/viewnior/
COMMENT=	Viewnior is a fast and simple image viewer
LICENSE=	gnu-gpl-v3

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_TOOLS+=	autoconf automake
USE_TOOLS+=	intltool pkg-config gmake msgfmt
USE_LANGUAGES=	c c++

BUILD_DEPENDS+=		gnome-common-[0-9]*:../../devel/gnome-common

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
