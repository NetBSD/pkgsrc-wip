# $NetBSD: Makefile,v 1.7 2007/01/15 09:01:40 ghen Exp $
#

DISTNAME=		wmii-3.1
PKGREVISION=		1
CATEGORIES=		wm
MASTER_SITES=		http://suckless.org/download/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://wmii.suckless.org/
COMMENT=		Third version of the window manager improved 2

NO_CONFIGURE=		yes

LDFLAGS+=-L${X11BASE}/lib ${COMPILER_RPATH_FLAG}${X11BASE}/lib

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	cmd/wm/wmii rc/* cmd/wm/wmii.1
SUBST_SED.path=		-e 's|CONFPREFIX|${PREFIX}/etc/|g'
SUBST_SED.path+=	-e 's|9PREFIX|${PREFIX}|g'

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-patch
SUBST_FILES.prefix=	config.mk
SUBST_SED.prefix=	-e s,/usr/local,${PREFIX},g
SUBST_SED.prefix+=	-e 's|/usr/X11R6|$${X11BASE}|g'
SUBST_SED.prefix+=	-e 's|/usr/X11R6|$${X11BASE}|g'
SUBST_SED.prefix+=	-e 's|CFLAGS = -O2|CFLAGS+=|g'
SUBST_SED.prefix+=	-e 's|LDFLAGS =|LDFLAGS+=|g'
SUBST_SED.prefix+=	-e 's|share/||'
SUBST_SED.prefix+=	-e 's|-g||g'
SUBST_SED.prefix+=	-e 's|/9||g'
SUBST_SED.prefix+=	-e 's|cc|${CC:Q}|g'

# TODO:
# This must probably be fixed. so no files were created in share/examples.
# They-r strictly necessary? or is just ok to get them from the $SYSCONFDIR?
#
#PKG_SYSCONFSUBDIR=      wmii-3
#EGDIR=                  ${PREFIX}/share/examples/wmii-3
#EGFILES=                extern kmode quit status welcome wmirc
#.for f in ${EGFILES}
#CONF_FILES+=            ${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
#.endfor

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
