# $NetBSD$

DISTNAME=	libmd-1.0.4
CATEGORIES=	devel
MASTER_SITES=	https://archive.hadrons.org/software/libmd/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vms@retrobsd.ddns.net
HOMEPAGE=	https://www.hadrons.org/software/libmd/
COMMENT=	Message Digest functions from BSD systems
LICENSE=	modified-bsd AND 2-clause-bsd AND isc AND beer-ware

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	src/libmd.pc.in

.include "../../mk/bsd.pkg.mk"
