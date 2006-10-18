# $NetBSD: Makefile,v 1.4 2006/10/18 13:58:14 kh-p Exp $
#

DISTNAME=		wmii-3.1
CATEGORIES=		wip wm
MASTER_SITES=		http://suckless.org/download/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://wmii.suckless.org/
COMMENT=		Third version of the window manager improved 2

CONFLICTS+=		wmii-2.*

NO_CONFIGURE=		yes

LDFLAGS+=-L${X11BASE}/lib -Wl,-R${X11BASE}/lib

SUBST_CLASSES     += vars pfx

SUBST_STAGE.vars   = post-patch
SUBST_FILES.vars   = cmd/wm/wmii rc/* cmd/wm/wmii.1
SUBST_SED.vars     = -e 's|CONFPREFIX|${PREFIX}/etc/|g'
SUBST_SED.vars    += -e 's|9PREFIX|${PREFIX}|g'

SUBST_STAGE.pfx    = patch
SUBST_FILES.pfx    = config.mk
SUBST_SED.pfx      = -e s,/usr/local,${PREFIX},g
SUBST_SED.pfx	  += -e 's|/usr/X11R6|$${X11BASE}|g'
SUBST_SED.pfx     += -e 's|/usr/X11R6|$${X11BASE}|g'
SUBST_SED.pfx     += -e 's|CFLAGS = -O2|CFLAGS+=|g'
SUBST_SED.pfx     += -e 's|LDFLAGS =|LDFLAGS+=|g'
SUBST_SED.pfx     += -e 's|share/||'
SUBST_SED.pfx     += -e 's|-g||g'
SUBST_SED.pfx     += -e 's|/9||g'
SUBST_SED.pfx     += -e 's|cc|${CC}|g'

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
