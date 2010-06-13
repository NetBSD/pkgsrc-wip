# $NetBSD: Makefile,v 1.19 2010/06/13 22:47:09 thomasklausner Exp $
#

DISTNAME=		kvirc-3.4.2
PKGREVISION=		1
CATEGORIES=		chat
MASTER_SITES=		http://kvirc.gmake.de/pub/kvirc/3.4.2/source/ \
			http://kvirc-ftp.visualscripts.com/3.4.2/source/ \
			ftp://dedimarbo.ath.cx/pub/kvirc/3.4.2/source/ \
			ftp://kvirc.eban-meban.com/3.4.2/source/ \
			ftp://ftp.kvirc.de/pub/kvirc/3.4.2/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		siflfran@hawo.stw.uni-erlangen.de
HOMEPAGE=		http://www.kvirc.net/
COMMENT=		QT based irc client

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake msgfmt perl
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--without-locale
CONFIGURE_ARGS+=	--with-big-channels
CONFIGURE_ARGS+=	--without-arts-support
CONFIGURE_ARGS+=	--with-aa-fonts
# because perl's buildlink3 file is broken (DynaLoader part)
CONFIGURE_ARGS+=	--disable-perl

PTHREAD_OPTS+=		require

UNWRAP_FILES+=		scripts/config/kvirc-config

#pre-configure:
#	cd ${WRKSRC} && aclocal
#	cd ${WRKSRC} && autoheader
#	cd ${WRKSRC} && automake -a --foreign -i
#	cd ${WRKSRC} && autoconf

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--with-ix86-asm
.endif

.include "../../audio/gsm/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
