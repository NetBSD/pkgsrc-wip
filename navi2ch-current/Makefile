# $NetBSD: Makefile,v 1.3 2012/10/03 18:15:31 asau Exp $

DISTNAME=	navi2ch-2.0.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}navi2ch-current-2.0.0
CATEGORIES=	chat
WRKSRC=		${WRKDIR}/navi2ch

CONFLICTS+=	navi2ch-[0-9]*

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://navi2ch.sourceforge.net/
COMMENT=	2ch BBS browser for Emacs (Git Current)
LICENSE=	gnu-gpl-v2

GIT_REPOSITORIES=	master
GIT_REPO.master=	git://navi2ch.git.sourceforge.net/gitroot/navi2ch/navi2ch
GIT_MODULE.master=	navi2ch

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
INFO_FILES=	yes
EMACS_MODULES=	base

CONFIGURE_ARGS+=	--with-icondir=${PREFIX}/share/navi2ch/icons
CONFIGURE_ARGS+=	${CONFIGURE_ARGS.${EMACS_FLAVOR}}

CONFIGURE_ARGS.emacs=	--with-lispdir=${EMACS_LISPPREFIX}/navi2ch
CONFIGURE_ARGS.xemacs=	--with-packagedir=${EMACS_LISPPREFIX:C|/lisp$||}

.include "../../wip/mk/git-package.mk"
.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
