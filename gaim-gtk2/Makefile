# $NetBSD: Makefile,v 1.2 2003/04/09 22:57:17 matthewluckie Exp $

DISTNAME=	gaim-0.60
CATEGORIES=	chat x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gaim/} \
		ftp://ftp.marko.net/pub/gaim/

MAINTAINER=	mjl@luckie.org.nz
HOMEPAGE=	http://gaim.sourceforge.net/
COMMENT=	GTK2 based client for the AOL Instant Messenger chat system

DEPENDS+=	gnome2-dirs>=1.1:../../misc/gnome2-dirs

CONFLICTS+=	gaim-[0-9]* gaim-gnome-[0-9]*

USE_GMAKE=		YES
USE_PERL5=		YES
USE_X11=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--disable-nas
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.libiconv}
CONFIGURE_ARGS+=	--enable-perl

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/include/X11/extensions/scrnsaver.h)
CONFIGURE_ARGS+=	--disable-screensaver
.endif

.include "../../audio/libao/buildlink2.mk"
.include "../../audio/libaudiofile/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../textproc/gtkspell/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
