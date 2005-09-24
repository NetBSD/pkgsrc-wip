# $NetBSD: Makefile,v 1.3 2005/09/24 07:59:29 gregschenzel Exp $
#

DISTNAME=		tzosdclock_1.0.2
CATEGORIES=		wip
MASTER_SITES=		http://www.unixdev.net/downloads/tzosdclock/1.0.2/

MAINTAINER=		inittab@unixdev.net
HOMEPAGE=		http://www.unixdev.net/projects/tzosdclock
COMMENT=		OnScreen Display Clock for Multiple Timezones

WRKSRC=		${WRKDIR}/tzosdclock
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../x11/xosd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
