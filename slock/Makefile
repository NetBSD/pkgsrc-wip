# $NetBSD: Makefile,v 1.3 2006/11/04 10:48:33 kh-p Exp $

DISTNAME=		slock-0.3
CATEGORIES=		x11
MASTER_SITES=		http://suckless.org/download/

MAINTAINER=		kh.p@no-log.org
HOMEPAGE=		http://tools.suckless.org/
COMMENT=		Simple screen locker

NO_CONFIGURE=		yes

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-patch
SUBST_FILES.prefix=	 config.mk
SUBST_SED.prefix=		-e s,/usr/local,${PREFIX},g
SUBST_SED.prefix+=		-e 's|/usr/X11R6|$${X11BASE}|g'
SUBST_SED.prefix+=		-e 's|/usr/X11R6|$${X11BASE}|g'
SUBST_SED.prefix+=		-e 's|CFLAGS =|CFLAGS+=|g'
SUBST_SED.prefix+=		-e 's|LDFLAGS =|LDFLAGS+=|g'
SUBST_SED.prefix+=		-e 's|cc|${CC:Q}|g'
SUBST_MESSAGE.prefix=		Fixing hardcoded paths.

.include "../../mk/bsd.prefs.mk"

.if !(${OPSYS:M*BSD} != "" || ${OPSYS} == "Darwin")
CFLAGS+=-DHAVE_SHADOW_H
.endif

.if !(${OPSYS} == "OpenBSD")
LDFLAGS+=-lcrypt
.endif

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
