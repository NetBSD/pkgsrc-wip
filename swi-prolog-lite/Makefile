# $NetBSD: Makefile,v 1.1.1.1 2004/04/22 16:46:04 mpasternak Exp $
# $Id: Makefile,v 1.1.1.1 2004/04/22 16:46:04 mpasternak Exp $

.include "../../wip/swi-prolog-lite/Makefile.common"

PKGNAME=		swi-prolog-lite-${SWIPLVERS}

MAINTAINER=		hubertf@NetBSD.org
COMMENT=		ISO/Edinburgh-style Prolog compiler

GNU_CONFIGURE=		# defined
USE_BUILDLINK3=		# defined
USE_GNU_READLINE=	# uses rl_event_hook() interface

SWIPL=			swi-prolog
CONFIGURE_ENV+=		PL="${SWIPL}"
CPPFLAGS+=		-D__unix__=1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
