# $NetBSD: Makefile,v 1.10 2012/10/07 16:22:56 asau Exp $
#

DISTNAME=		serlook-0.2.4-KDE3
PKGNAME=		serlook-0.2.4
PKGREVISION=		5
CATEGORIES=		kde comms
MASTER_SITES=	http://serlook.sunsite.dk/

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://serlook.sunsite.dk/
COMMENT=		SerLooK is a tool aimed to inspect and debug serial line data traffic


WRKSRC=			${WRKDIR}/${DISTNAME:C/-KDE3//}/

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
