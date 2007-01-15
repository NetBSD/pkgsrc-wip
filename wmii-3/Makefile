# $NetBSD: Makefile,v 1.8 2007/01/15 09:58:44 ghen Exp $
#

DISTNAME=		wmii-3.1
PKGREVISION=		2
CATEGORIES=		wm
MASTER_SITES=		http://suckless.org/download/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://wmii.suckless.org/
COMMENT=		Third version of the window manager improved 2

NO_CONFIGURE=		yes

BUILD_DEFS+=		PKG_SYSCONFBASE

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	cmd/wm/wmii rc/wmiirc cmd/wm/wmii.1
SUBST_SED.path+=	-e 's|CONFPREFIX|${PKG_SYSCONFBASE}|g'

PKG_SYSCONFSUBDIR=	wmii-3
EGBASE=			${PREFIX}/share/examples
EGDIR=			${EGBASE}/wmii-3
EGFILES=		quit status welcome wmiirc
CONF_FILES_MODE=	755

.for f in ${EGFILES}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

MAKE_ENV+=		CONFPREFIX=${EGBASE}
MAKE_ENV+=		MANPREFIX=${PREFIX}/${PKGMANDIR}

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
