# $NetBSD: Makefile,v 1.3 2005/05/24 10:31:15 rillig Exp $
#

DISTNAME=	orpie-1.4.1
CATEGORIES=	math
MASTER_SITES=	http://www.eecs.umich.edu/~pelzlpj/orpie/

MAINTAINER=	tnn@netilium.org
HOMEPAGE=	http://www.eecs.umich.edu/~pelzlpj/orpie/
COMMENT=	Curses-based reverse polish notation (RPN) calculator

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--with-ncurses

INCOMPAT_CURSES+=	NetBSD-*

.include "../../mk/bsd.prefs.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
