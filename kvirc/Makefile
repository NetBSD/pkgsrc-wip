# $NetBSD: Makefile,v 1.17 2010/01/18 09:38:26 thomasklausner Exp $
#

DISTNAME=		kvirc-3.2.3
PKGREVISION=		4
CATEGORIES=		chat
MASTER_SITES=		ftp://ftp.kvirc.net/pub/kvirc/snapshots/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		siflfran@hawo.stw.uni-erlangen.de
HOMEPAGE=		http://www.kvirc.net/
COMMENT=		QT based irc client

USE_TOOLS+=		gmake msgfmt
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
