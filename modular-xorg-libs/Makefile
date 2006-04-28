# $NetBSD: Makefile,v 1.5 2006/04/28 02:50:14 jeremy-c-reed Exp $

# probably a meta package is not needed
# could just install the libX11 and others

# later add some X11_COMPONENTS that can list needed components
# if a package has the defined and using modular-xorg then just
# depend on those, if not just depend on this meta package

DISTNAME=	modular-xorg-libs-7.0
PKGREVISION=	5
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Meta package for modular X.org X libraries

# todo: depend on specific versions or "nb" revisions
DEPENDS+=	libX11>=0.99.0:../../wip/libX11
DEPENDS+=	libXau>=0.99.0:../../wip/libXau
DEPENDS+=	libXaw>=0.99.0:../../wip/libXaw
DEPENDS+=	libXext>=0.99.0:../../wip/libXext
DEPENDS+=	libXfont>=0.99.0:../../wip/libXfont
DEPENDS+=	libXi>=1.0.0:../../wip/libXi
DEPENDS+=	libXinerama>=1.0.1:../../wip/libXinerama
DEPENDS+=	libXmu>=1.0.0:../../wip/libXmu
DEPENDS+=	libXt>=0.99.2:../../wip/libXt
DEPENDS+=	libXxf86misc>=1.0.0:../../wip/libXxf86misc
DEPENDS+=	libXxf86vm>=1.0.0:../../wip/libXxf86vm
DEPENDS+=	libxkbfile>=0.99.1:../../wip/libxkbfile
DEPENDS+=	libxkbui>=1.0.1:../../wip/libxkbui

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
