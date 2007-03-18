# $NetBSD: Makefile,v 1.5 2007/03/18 21:34:05 cosmedbr Exp $

DISTNAME=		slock-0.6
CATEGORIES=		x11
MASTER_SITES=		http://suckless.org/download/

MAINTAINER=		cosmedbr@users.sourceforge.net
HOMEPAGE=		http://tools.suckless.org/
COMMENT=		Simple screen locker

NO_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if !(${OPSYS:M*BSD} != "" || ${OPSYS} == "Darwin")
CFLAGS+=-DHAVE_SHADOW_H
.endif

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
