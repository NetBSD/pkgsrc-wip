# $NetBSD: Makefile,v 1.9 2004/05/20 20:23:26 timbishop Exp $

DISTNAME=	libstatgrab-0.10
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.mirror.ac.uk/sites/ftp.i-scream.org/pub/i-scream/libstatgrab/ \
		http://www.mirror.ac.uk/sites/ftp.i-scream.org/pub/i-scream/libstatgrab/ \
		ftp://ftp.i-scream.org/pub/i-scream/libstatgrab/ \
		http://www.i-scream.org/pub/i-scream/libstatgrab/

MAINTAINER=	tim@bishnet.net
HOMEPAGE=	http://www.i-scream.org/libstatgrab/
COMMENT=	Provides a useful interface to system statistics

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
PKGCONFIG_OVERRIDE+=	libstatgrab.pc.in
USE_BUILDLINK3=	yes

CONFIGURE_ARGS+=	--disable-examples

.include "../../mk/bsd.prefs.mk"

.if defined(WITHOUT_STATGRAB)
CONFIGURE_ARGS+=	--disable-statgrab
PLIST_SUBST+=		STATGRAB="@comment "
.else
PLIST_SUBST+=		STATGRAB=""
.endif
BUILD_DEFS+=		WITHOUT_STATGRAB

.if defined(WITHOUT_SAIDAR)
CONFIGURE_ARGS+=	--disable-saidar
PLIST_SUBST+=		SAIDAR="@comment "
.else
PLIST_SUBST+=		SAIDAR=""
.include "../../devel/ncurses/buildlink3.mk"
.endif
BUILD_DEFS+=		WITHOUT_SAIDAR

.include "../../mk/bsd.pkg.mk"
