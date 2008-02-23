# $NetBSD: Makefile,v 1.1.1.2 2008/02/23 10:35:56 smoppy Exp $

DISTNAME=	tmux-0.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tmux/}

MAINTAINER=	clamiax@gmail.com
HOMEPAGE=	http://tmux.sourceforge.net/
COMMENT=	BSD-licensed terminal multiplexer (GNU Screen alternative)

NO_CONFIGURE=	yes

# Makefile
SUBST_CLASSES=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing distribution Makefile..
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile=	-e "s,-I-,-I/usr/pkg/include,"
SUBST_SED.makefile+=	-e "s,/man/,/${PKGMANDIR}/,"

# Preferences handling framework
.include "../../mk/bsd.prefs.mk"

# Unprivileged owner/group
.if defined(UNPRIVILEGED) && !empty(UNPRIVILEGED:M[Yy][Ee][Ss])
SUBST_SED.makefile+=	-e 's/-g bin -o root/-o ${UNPRIVILEGED_USER} -g ${UNPRIVILEGED_GROUP}/g'
.endif

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
