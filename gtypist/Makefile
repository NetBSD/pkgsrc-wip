# $NetBSD: Makefile,v 1.3 2006/02/25 11:33:00 rillig Exp $
#

DISTNAME=		gtypist-2.7
CATEGORIES=		textproc
MASTER_SITES=		ftp://ftp.gnu.org/gnu/gtypist/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		ftp://ftp.gnu.org/gnu/gtypist/
COMMENT=		Universal typing tutor

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_NCURSES=		yes	# uses typeahead()
BUILDLINK_TRANSFORM+=	l:curses:ncurses
REPLACE_PERL+=		typefortune
USE_TOOLS+=		perl:run

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
