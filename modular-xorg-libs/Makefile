# $NetBSD: Makefile,v 1.1.1.1 2005/11/12 02:14:45 jeremy-c-reed Exp $

# probably a meta package is not needed
# could just install the libX11 and others

# later add some X11_COMPONENTS that can list needed components
# if a package has the defined and using modular-xorg then just
# depend on those, if not just depend on this meta package

DISTNAME=	modular-xorg-libs-7.0
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Meta package for modular X.org X libraries

# todo: depend on specific versions or "nb" revisions
DEPENDS+=	libX11>=0.99.0:../../wip/libX11
DEPENDS+=	libXt>=0.99.2:../../wip/libXt

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
