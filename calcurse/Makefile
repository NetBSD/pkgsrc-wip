# $NetBSD: Makefile,v 1.4 2011/10/24 22:11:54 crocusino Exp $
#

DISTNAME=	calcurse-2.9.2
CATEGORIES=	time
MASTER_SITES=	http://calcurse.org/files/

MAINTAINER=	jan.smydke@jh-inst.cas.cz
HOMEPAGE=	http://calcurse.org/
COMMENT=	Text based calendar and scheduling application
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

# force to use ncurses from pkgsrc
INCOMPAT_CURSES=	NetBSD-*-*

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
