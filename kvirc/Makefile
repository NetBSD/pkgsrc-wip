# $NetBSD: Makefile,v 1.4 2004/02/17 02:55:46 blef Exp $
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

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--without-locale
CONFIGURE_ARGS+=	--with-big-channels
CONFIGURE_ARGS+=	--without-arts-support
CONFIGURE_ARGS+=	--with-aa-fonts

PTHREAD_OPTS+=		require
AUTOMAKE_REQD=		1.5

pre-configure:
	cd ${WRKSRC};			\
	${ACLOCAL};			\
	${AUTOHEADER};			\
	${AUTOMAKE} -a --foreign -i;	\
	${AUTOCONF}

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--with-ix86-asm
.endif

.include "../../audio/gsm/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../x11/qt3-libs/buildlink2.mk"

.include "../../mk/automake.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
