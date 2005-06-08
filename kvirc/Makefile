# $NetBSD: Makefile,v 1.11 2005/06/08 15:47:00 dillo Exp $
#

DISTNAME=		kvirc-3.0.0-beta2
PKGNAME=		${DISTNAME:S/-b/b/}
CATEGORIES=		chat
MASTER_SITES=		ftp://ftp.kvirc.de/pub/kvirc/3.0.0-beta2/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		siflfran@hawo.stw.uni-erlangen.de
HOMEPAGE=		http://www.kvirc.net/
COMMENT=		QT based irc client

BUILD_USES_MSGFMT=	yes

USE_TOOLS+=		gmake automake
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--without-locale
CONFIGURE_ARGS+=	--with-big-channels
CONFIGURE_ARGS+=	--without-arts-support
CONFIGURE_ARGS+=	--with-aa-fonts

PTHREAD_OPTS+=		require

pre-configure:
	cd ${WRKSRC} && aclocal
	cd ${WRKSRC} && autoheader
	cd ${WRKSRC} && automake -a --foreign -i
	cd ${WRKSRC} && autoconf

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
