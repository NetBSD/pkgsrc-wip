# $NetBSD$

DISTNAME=	libgringotts-1.2.1
CATEGORIES=	security
MASTER_SITES=	https://sourceforge.net/projects/gringotts.berlios/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	robn@gmx.com
HOMEPAGE=	https://libgringotts.sourceforge.net/
COMMENT=	Gringotts data encapsulation and encryption library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

.include "../../security/libmcrypt/buildlink3.mk"
.include "../../security/mhash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
