# $NetBSD: Makefile,v 1.4 2004/02/10 21:50:20 timbishop Exp $
#

DISTNAME=	libstatgrab-0.8.2
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

CONFIGURE_ARGS+=	--disable-examples

.if defined(WITHOUT_STATGRAB)
CONFIGURE_ARGS+=	--disable-statgrab
PLIST_SUBST+=		STATGRAB="@comment "
.else
PLIST_SUBST+=		STATGRAB=""
.endif

.if defined(WITHOUT_SAIDAR)
CONFIGURE_ARGS+=	--disable-saidar
PLIST_SUBST+=		SAIDAR="@comment "
.else
PLIST_SUBST+=		SAIDAR=""
.endif

.if defined(WITHOUT_SETGID_BINARIES)
CONFIGURE_ARGS+=	--disable-setgid-binaries
.endif

.include "../../mk/bsd.pkg.mk"
