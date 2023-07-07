# $NetBSD$

DISTNAME=	nitrogen-1.6.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=l3ib/}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	http://projects.l3ib.org/nitrogen/
COMMENT=	Background browser and setter
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c c++
USE_TOOLS+=		autoconf autoreconf automake bash pkg-config
CONFIGURE_ARGS+=	--disable-inotify
CXXFLAGS+=		-std=c++11
GCC_REQD+=		4.9

REPLACE_BASH=	data/icon-theme-installer

pre-configure:
	${RUN} cd ${WRKSRC} && autoreconf -fi

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
