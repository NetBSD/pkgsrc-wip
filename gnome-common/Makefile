# $NetBSD$

DISTNAME=	gnome-common-3.18.0
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.gnome.org/GNOME/gnome-common/-/archive/3.18.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/gnome-common/-/archive/3.18.0/
COMMENT=	Generic M4 macros for GNOME development
LICENSE=	gnu-gpl-v3

WRKSRC=			${WRKDIR}/gnome-common-3.18.0
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake automake intltool autoreconf
USE_PKGLOCALEDIR=	yes


pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=1 ./autogen.sh

.include "../../mk/bsd.pkg.mk"
