# $NetBSD: Makefile,v 1.2 2010/06/12 15:51:15 crocusino Exp $
#

DISTNAME=	calcurse-2.8
CATEGORIES=	time
MASTER_SITES=	ftp://ftp2.culot.org/culot/

MAINTAINER=	jan.smydke@jh-inst.cas.cz
HOMEPAGE=	http://culot.org/calcurse/
COMMENT=	Text based calendar and scheduling application

LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

# force to use ncurses from pkgsrc
INCOMPAT_CURSES=        NetBSD-*-*

# url2pkg-marker (please do not remove this line.)
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
