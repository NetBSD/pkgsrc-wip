# $NetBSD: Makefile,v 1.5 2007/10/26 12:42:36 hfath Exp $
#

DISTNAME=		gtypist-2.7
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GNU:=gtypist/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.gnu.org/software/gtypist/
COMMENT=		Universal typing tutor

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_NCURSES=		yes	# uses typeahead()
BUILDLINK_TRANSFORM+=	l:curses:ncurses
REPLACE_PERL+=		typefortune
USE_TOOLS+=		makeinfo perl:run

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
