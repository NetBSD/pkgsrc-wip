# $NetBSD: Makefile,v 1.1.1.1 2004/07/15 06:19:23 ianzag Exp $
#

DISTNAME=		serlook-0.2.4-KDE3
PKGNAME=		serlook-0.2.4
CATEGORIES=		kde comms
MASTER_SITES=	http://serlook.sunsite.dk/

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://serlook.sunsite.dk/
COMMENT=		SerLooK is a tool aimed to inspect and debug serial line data traffic

WRKSRC=			${WRKDIR}/${DISTNAME:C/-KDE3//}/

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
