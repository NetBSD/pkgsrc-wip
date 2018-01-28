# $NetBSD: Makefile,v 1.7 2015/08/18 20:53:24 yhardy Exp $

DISTNAME=	calcurse-4.2.2
CATEGORIES=	time
MASTER_SITES=	http://calcurse.org/files/

MAINTAINER=	jan.smydke@jh-inst.cas.cz
HOMEPAGE=	http://calcurse.org/
COMMENT=	Text based calendar and scheduling application
LICENSE=	2-clause-bsd

USE_TOOLS+=	gmake msgfmt msgmerge xgettext
GNU_CONFIGURE=	yes

# force to use ncurses from pkgsrc
#INCOMPAT_CURSES=	NetBSD-*-*
REPLACE_PYTHON=		contrib/caldav/calcurse-caldav
FAKE_NCURSES=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
