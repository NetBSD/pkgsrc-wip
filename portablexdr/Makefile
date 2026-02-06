# $NetBSD$

DISTNAME=	portablexdr-4.9.1
CATEGORIES=	devel
MASTER_SITES=	https://people.redhat.com/~rjones/portablexdr/files/

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://people.redhat.com/~rjones/portablexdr/
COMMENT=	XDR library for Unix, Linux, Windows and Mac OS X
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

BUILDLINK_TRANSFORM=	rm:-Werror
FORCE_C_STD=    	 c89

.include "../../mk/bsd.pkg.mk"
