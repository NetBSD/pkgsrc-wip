# $NetBSD: Makefile,v 1.6 2004/03/14 16:02:30 timbishop Exp $

DISTNAME=	libstatgrab-0.9
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.mirror.ac.uk/sites/ftp.i-scream.org/pub/i-scream/libstatgrab/ \
		http://www.mirror.ac.uk/sites/ftp.i-scream.org/pub/i-scream/libstatgrab/ \
		ftp://ftp.i-scream.org/pub/i-scream/libstatgrab/ \
		http://www.i-scream.org/pub/i-scream/libstatgrab/

MAINTAINER=	tim@bishnet.net
HOMEPAGE=	http://www.i-scream.org/libstatgrab/
COMMENT=	Provides a useful interface to system statistics

DIST_SUBDIR=	i-scream
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libstatgrab.pc.in
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
.endif
BUILD_DEFS+=		WITHOUT_SAIDAR

.include "../../mk/bsd.pkg.mk"
