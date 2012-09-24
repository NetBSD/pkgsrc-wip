# $NetBSD: Makefile,v 1.6 2012/09/24 18:26:51 asau Exp $
#

DISTNAME=	calcurse-2.9.2
CATEGORIES=	time
MASTER_SITES=	http://calcurse.org/files/

MAINTAINER=	jan.smydke@jh-inst.cas.cz
HOMEPAGE=	http://calcurse.org/
COMMENT=	Text based calendar and scheduling application
LICENSE=	2-clause-bsd

USE_TOOLS+=	gmake msgfmt msgmerge xgettext
GNU_CONFIGURE=	yes

# force to use ncurses from pkgsrc
INCOMPAT_CURSES=	NetBSD-*-*

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
