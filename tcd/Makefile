# $NetBSD: Makefile,v 1.1 2004/06/16 15:28:10 rillig Exp $
#

DISTNAME=		tcd-2.2.0
CATEGORIES=		audio
MASTER_SITES=		http://savannah.gnu.org/download/tcd/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roland.illig@gmx.de
HOMEPAGE=		http://savannah.gnu.org/download/tcd/
COMMENT=		Audio CD player using ncurses and SDL

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

DEPENDS+=		SDL:../../devel/SDL

.include "../../mk/bsd.pkg.mk"
