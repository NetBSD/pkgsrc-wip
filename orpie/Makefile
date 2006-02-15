# $NetBSD: Makefile,v 1.4 2006/02/15 16:47:20 tnn2 Exp $
#

DISTNAME=	orpie-1.4.3
CATEGORIES=	math
MASTER_SITES=	http://www.eecs.umich.edu/~pelzlpj/orpie/

MAINTAINER=	tnn+nbsd@nygren.pp.se
HOMEPAGE=	http://www.eecs.umich.edu/~pelzlpj/orpie/
COMMENT=	Curses-based reverse polish notation (RPN) calculator

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--with-ncurses

INCOMPAT_CURSES+=	NetBSD-*-*

.include "../../mk/bsd.prefs.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
