# $NetBSD: Makefile,v 1.1.1.1 2003/08/22 14:52:40 id9848949 Exp $

DISTNAME=	mc-4.6.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ibiblio.org/pub/Linux/utils/file/managers/mc/ \
		${MASTER_SITE_SUNSITE:=utils/file/managers/mc/}

MAINTAINER=	pavel.arnost@clnet.cz
HOMEPAGE=	http://www.ibiblio.org/mc/
COMMENT=	User-friendly file manager and visual shell

BUILD_DEPENDS=	pkgconfig:../../devel/pkgconfig

AUTOCONF_REQD=	2.57

.include "../../mk/bsd.prefs.mk"

MC_ENABLE_CHARSET=
MC_ENABLE_X11=
MC_ENABLE_LARGEFILE=
MC_ENABLE_SUBSHELL=
MC_ENABLE_VFS=
MC_ENABLE_EDIT=
MC_ENABLE_SAMBA=
MC_SCREEN_LIBRARY= slang

USE_BUILDLINK2=
GNU_CONFIGURE=
USE_GMAKE=
USE_PKGLOCALEDIR=
PKG_DEVELOPER=

PLIST_SRC=  		${PKGDIR}/PLIST

.if ${OPSYS} == "Linux"
PLIST_SRC+=			${PKGDIR}/PLIST.cons.saver
.endif

# we need working e2fsprogs and gpm packages first
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--without-ext2undel \
		--without-gpm-mouse

.if defined(MC_ENABLE_SAMBA)
MC_ENABLE_VFS=
CONFIGURE_ARGS+=	--with-samba
.else
CONFIGURE_ARGS+=	--without-samba
.endif

.if !defined(MC_ENABLE_LARGEFILE)
CONFIGURE_ARGS+=	--disable-largefile
.endif

.if defined(MC_ENABLE_X11)
USE_X11BASE=
CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--without-x
.endif

.if defined(MC_ENABLE_VFS)
CONFIGURE_ARGS+=	--with-vfs
PLIST_SRC+=			${PKGDIR}/PLIST.vfs
.else
CONFIGURE_ARGS+=	--without-vfs
.endif

.if defined(MC_ENABLE_EDIT)
CONFIGURE_ARGS+=	--with-edit
PLIST_SRC+=			${PKGDIR}/PLIST.mcedit
.else
CONFIGURE_ARGS+=	--without-edit
.endif

.if defined(MC_ENABLE_SUBSHELL)
CONFIGURE_ARGS+=	--with-subshell
.else
CONFIGURE_ARGS+=	--without-subshell
.endif

.if defined(MC_ENABLE_CHARSET)
CONFIGURE_ARGS+=	--enable-charset
.include "../../converters/libiconv/buildlink2.mk"
PLIST_SRC+=			${PKGDIR}/PLIST.charset
.else
CONFIGURE_ARGS+=	--disable-charset
.endif

.if ${MC_SCREEN_LIBRARY} == "slang"
CONFIGURE_ARGS+=	--with-screen=slang
.include "../../devel/libslang/buildlink2.mk"
.elif ${MC_SCREEN_LIBRARY} == "ncurses"
CONFIGURE_ARGS+=	--with-screen=ncurses
.include "../../devel/ncurses/buildlink2.mk"
.else
CONFIGURE_ARGS+=	--with-screen=mcslang
.endif

pre-configure:
	cd ${WRKSRC}/vfs/samba; ${AUTOCONF}

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"

