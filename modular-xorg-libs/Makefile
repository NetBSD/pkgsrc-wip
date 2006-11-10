# $NetBSD: Makefile,v 1.8 2006/11/10 18:08:25 jeremy-c-reed Exp $

# probably a meta package is not needed
# could just install the libX11 and others

# later add some X11_COMPONENTS that can list needed components
# if a package has the defined and using modular-xorg then just
# depend on those, if not just depend on this meta package

DISTNAME=	modular-xorg-libs-7.0
PKGREVISION=	7
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Meta package for modular X.org X libraries

# todo: depend on specific versions or "nb" revisions
DEPENDS+=	libX11>=0.99.0:../../x11/libX11
DEPENDS+=	libXau>=0.99.0:../../x11/libXau
DEPENDS+=	libXaw>=0.99.0:../../x11/libXaw
DEPENDS+=	libXext>=0.99.0:../../x11/libXext
DEPENDS+=	libXfont>=0.99.0:../../x11/libXfont
DEPENDS+=	libXi>=1.0.0:../../x11/libXi
DEPENDS+=	libXinerama>=1.0.1:../../x11/libXinerama
DEPENDS+=	libXmu>=1.0.0:../../x11/libXmu
DEPENDS+=	libXp>=1.0.0:../../x11/libXp
DEPENDS+=	libXt>=0.99.2:../../x11/libXt
DEPENDS+=	libXxf86misc>=1.0.0:../../wip/libXxf86misc
DEPENDS+=	libXxf86vm>=1.0.0:../../wip/libXxf86vm
DEPENDS+=	libxkbfile>=0.99.1:../../x11/libxkbfile
DEPENDS+=	libxkbui>=1.0.1:../../wip/libxkbui

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
