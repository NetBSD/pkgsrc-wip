# $NetBSD: Makefile,v 1.6 2004/08/17 18:28:09 tvierling Exp $
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

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
LIBTOOL_LA_FILES+=	lib/libkvilib.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkviabout.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvialiaseditor.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvichan.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvichannelsjoin.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkviclock.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvicodetester.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkviconfig.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvidcc.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvidialog.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvidockwidget.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvieditor.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvieventeditor.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvifile.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvihelp.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkviident.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkviiograph.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvilag.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvilamerizer.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvilinks.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvilist.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvilog.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvilogview.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvimask.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvimircimport.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvimp3player.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvimy.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkviobjects.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvioffer.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvioptions.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvipopupeditor.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkviraweditor.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkviregchan.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvireguser.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvirijndael.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvisetup.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvisnd.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvisocketspy.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvispaste.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvistr.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvisystem.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvitb_options.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvitb_winops.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkviterm.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvitip.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvitmphighlight.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvitoolbar.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkvitoolbareditor.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkviurl.la
LIBTOOL_LA_FILES+=	share/kvirc/3.0.0-beta2/modules/libkviwindow.la
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

.include "../../audio/gsm/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"

.include "../../mk/automake.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
