# $NetBSD: Makefile,v 1.3 2011/06/20 20:01:36 ryo-on Exp $
#

DISTNAME=	libburn-1.1.0.pl01
PKGNAME=	${DISTNAME:S/pl//}
CATEGORIES=	sysutils
MASTER_SITES=	http://files.libburnia-project.org/releases/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://libburnia-project.org/wiki/Libburn
COMMENT=	library by which preformatted data get onto optical media
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME:S/.pl01//}
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libburn-1.pc.in

.include "../../mk/bsd.pkg.mk"
