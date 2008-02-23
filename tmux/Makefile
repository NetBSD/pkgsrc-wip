# $NetBSD: Makefile,v 1.2 2008/02/23 13:50:52 smoppy Exp $

DISTNAME=	tmux-0.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tmux/}

MAINTAINER=	clamiax@gmail.com
HOMEPAGE=	http://tmux.sourceforge.net/
COMMENT=	BSD-licensed terminal multiplexer (GNU Screen alternative)

NO_CONFIGURE=	yes
USE_NCURSES=	# uses ncurses internals

.if 0

# Makefile
SUBST_CLASSES=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing distribution Makefile..
SUBST_FILES.makefile=	${MAKE_FILE}
SUBST_SED.makefile=	-e "s,/man/,/${PKGMANDIR}/,"

# Preferences handling framework
.include "../../mk/bsd.prefs.mk"

# Unprivileged owner/group
.if defined(UNPRIVILEGED) && !empty(UNPRIVILEGED:M[Yy][Ee][Ss])
SUBST_SED.makefile+=	-e 's/-g bin -o root/-o ${UNPRIVILEGED_USER} -g ${UNPRIVILEGED_GROUP}/g'
.endif

.endif

# compat/strtonum.c: replace "tmux.h" with "../tmux.h"
SUBST_CLASSES+=		header
SUBST_STAGE.header=	pre-build
SUBST_MESSAGE.header=	Fixing distribution headers..
SUBST_FILES.header=	compat/strtonum.c
SUBST_SED.header=	-e "s,tmux.h,../tmux.h,"

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
