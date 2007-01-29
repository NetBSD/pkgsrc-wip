# $NetBSD: Makefile,v 1.1 2007/01/29 08:55:31 bsadewitz Exp $
#

DISTNAME=	xkill-1.0.1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/releases/individual/app/
COMMENT=	X kill window utility from modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c

WRKSRC=		${WRKDIR}/xkill-1.0.1
GNU_CONFIGURE=	yes

.include "../../x11/libXmu/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
