# $NetBSD: Makefile,v 1.6 2012/10/23 10:23:06 thomasklausner Exp $

DISTNAME=		fvwm-1.24r-tch1
PKGNAME=		${DISTNAME:S/fvwm/fvwm1/:S/-tch/tch/}
CATEGORIES=		x11 wm
MASTER_SITES=		ftp://ftp.bsdprojects.net/pub/bsdprojects/fvwm/

MAINTAINER=		tonnerre@NetBSD.org
HOMEPAGE=		http://fvwm.bsdprojects.net/
COMMENT=		Virtual window manager for X

CONFLICTS=		fvwm2-[0-9]* fvwm1-[0-9]* fvwm>=1


GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf automake

post-configure:
	find ${WRKDIR} -name Makefile -print | while read file; do	\
		sed -e's/ -I$$//g' $$file > $$file.new;			\
		mv $$file.new $$file;					\
	done

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
