# $NetBSD: Makefile,v 1.6 2007/12/31 22:12:13 hoka_adam Exp $

DISTNAME=		slock-0.6
CATEGORIES=		x11
PKGREVISION=		1
MASTER_SITES=		http://suckless.org/download/

MAINTAINER=		cosmedbr@users.sourceforge.net
HOMEPAGE=		http://tools.suckless.org/
COMMENT=		Simple screen locker

NO_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if !(${OPSYS:M*BSD} != "" || ${OPSYS} == "Darwin")
CFLAGS+=-DHAVE_SHADOW_H
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
