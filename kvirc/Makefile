# $NetBSD: Makefile,v 1.1.1.1 2003/09/22 16:18:26 xtraeme Exp $
#

DISTNAME=		kvirc-3.0.0-beta2
CATEGORIES=		chat
MASTER_SITES=		ftp://ftp.kvirc.de/pub/kvirc/3.0.0-beta2/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		siflfran@hawo.stw.uni-erlangen.de
HOMEPAGE=		http://www.kvirc.net
COMMENT=		A QT based irc client

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+= --without-locale \
	--with-big-channels \
	--without-arts-support \
	--with-aa-fonts \
	--without-kde-support

USE_PKGLOCALEDIR=	yes
PTHREAD_OPTS+=		require
USE_LIBTOOL=		YES
USE_GMAKE=		YES
AUTOMAKE_REQD=		1.5

pre-configure:
	cd ${WRKSRC};	\
	${ACLOCAL};	\
	${AUTOHEADER};	\
	${AUTOMAKE} -a --foreign -i;	\
	${AUTOCONF}

.include "../../mk/ossaudio.buildlink2.mk"
.if defined(HAVE_OSS) && (${HAVE_OSS} == "YES")
CONFIGURE_ENV+=		ac_cv_libossaudio__oss_ioctl=no
.endif
.include "../../mk/automake.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"
.include "../../audio/gsm/buildlink2.mk"
.include "../../audio/esound/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../devel/libtool/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
