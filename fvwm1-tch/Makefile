# $NetBSD: Makefile,v 1.2 2007/02/27 20:51:31 netcap Exp $

DISTNAME=		fvwm-1.24r-tch1
PKGNAME=		${DISTNAME:S/fvwm/fvwm1/:S/-tch/tch/}
CATEGORIES=		x11 wm
MASTER_SITES=		ftp://ftp.bsdprojects.net/pub/bsdprojects/fvwm/

MAINTAINER=		tonnerre@bsdprojects.net
HOMEPAGE=		http://fvwm.bsdprojects.net/
COMMENT=		Virtual window manager for X

CONFLICTS=		fvwm2-[0-9]* fvwm1-[0-9]* fvwm>=1

GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf automake

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
