# $NetBSD: Makefile,v 1.12 2007/06/08 07:17:44 uebayasi Exp $

DISTNAME=	emacs-22.1
CATEGORIES=	editors
COMMENT=	GNU editing macros (editor)

#.include "../../editors/emacs22/Makefile.common"
.include "../../wip/emacs22/Makefile.common"

CONFLICTS+=	emacs-nox11-[0-9]*

CONFIGURE_ARGS+=	--srcdir=${WRKSRC:Q}

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
