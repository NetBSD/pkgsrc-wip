# $NetBSD: Makefile,v 1.1.1.1 2003/04/09 11:12:00 matthewluckie Exp $

DISTNAME=	gaim-0.60
CATEGORIES=	chat x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gaim/} \
		ftp://ftp.marko.net/pub/gaim/

MAINTAINER=	mjl@luckie.org.nz
HOMEPAGE=	http://gaim.sourceforge.net/
COMMENT=	GTK+-2.0 based client for AOL's Instant Messenger chat system

DEPENDS+=	gnome2-dirs>=1.0:../../misc/gnome2-dirs

CONFLICTS+=	gaim-[0-9]* gaim-gnome-[0-9]*

USE_GMAKE=		YES
USE_X11BASE=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--disable-nas
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.libiconv}
CONFIGURE_ARGS+=	--enable-perl

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/include/X11/extensions/scrnsaver.h)
CONFIGURE_ARGS+=	--disable-screensaver
.endif

.if !exists(${PREFIX}/include/gtkspell-2.0/gtkspell/gtkspell.h)
CONFIGURE_ARGS+=	--disable-gtkspell
.else
.include "../../textproc/gtkspell/buildlink2.mk"
.endif

.include "../../converters/libiconv/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../audio/libao/buildlink2.mk"
.include "../../audio/libaudiofile/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

