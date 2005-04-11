# $NetBSD: Makefile,v 1.5 2005/04/11 21:15:37 tvierling Exp $
# based on slrn-pl.spec from PLD Linux (http://www.pld-linux.org)
#
# SLRN_PL_FACES - build both slrnfaces (x11) and txtfaces extensions
# - both needs faces package

DISTNAME=	slrn-pl-1.4.3-2
CATEGORIES=	news
MASTER_SITES=	http://slrn-pl.zamiast.net/programy/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	aniou@smutek.pl
HOMEPAGE=	http://slrn-pl.zamiast.net/
COMMENT=	Highly customizable threaded newsreader (PoLished version)

PKG_SYSCONFSUBDIR=	slrn-pl
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=--disable-inews \
		--enable-spool \
		--enable-grouplens \
		--enable-setgid-code \
		--enable-mid-cache \
		--with-gen-mid \
		--with-slrnpull \
		--with-contrib \
		--with-ssl \
		--with-ssl-library=/usr \
		--with-ssl-includes=/usr \
		--with-libdir=${PREFIX}/lib/slrn \
		--sysconfdir=${PKG_SYSCONFDIR} \
		--with-localedir=${PREFIX}/${PKGLOCALEDIR}/locale

.include "../../mk/bsd.prefs.mk"

.if defined(SLRN_PL_FACES)
USE_X11=        	YES
CONFIGURE_ARGS+= 	--with-txtface --with-slrnface
PLIST_SRC+=             ${PKGDIR}/PLIST.faces
.include "../../mail/faces/buildlink3.mk"
.else
CONFIGURE_ARGS+= 	--without-txtface --without-slrnface
.endif

PLIST_SRC+=             ${PKGDIR}/PLIST

.include "../../devel/libslang/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
