# $NetBSD$

DISTNAME=	libdivecomputer-0.7.0
CATEGORIES=	misc
MASTER_SITES=	https://libdivecomputer.org/releases/

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://libdivecomputer.org/
COMMENT=	Library for communication with dive computers
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf automake

# Required only because we've modified configure.ac.
pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoreconf -fi

.include "../../mk/bsd.pkg.mk"
