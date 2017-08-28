# $NetBSD$

DISTNAME=	freeswitch-${VERSION}
VERSION=	1.6.19
CATEGORIES=	net
MASTER_SITES=	http://files.freeswitch.org/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	angelmadames@gmail.com	
HOMEPAGE=	http://www.freeswitch.org/
COMMENT=	FreeSwitch SoftSwitch
LICENSE=	mpl-1.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	libtool */libtool */*/libtool */*/*/libtool
USE_LANGUAGES=		c c++
USE_TOOLS+=		automake autoconf gmake perl pkg-config

BUILD_DEFS+=		VARBASE

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/bin
CONFIGURE_ARGS+=	--bindir=${PREFIX}/bin
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/db/freeswitch
CONFIGURE_ARGS+=	--datarootdir=${PREFIX}/share
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--htmldir=${PREFIX}/doc
CONFIGURE_ARGS+=	--dvidir=${PREFIX}/doc
CONFIGURE_ARGS+=	--psdir=${PREFIX}/doc
CONFIGURE_ARGS+=	--with-cachedir=${VARBASE}/cache/freeswitch
CONFIGURE_ARGS+=	--with-storagedir=${VARBASE}/db/freeswitch
CONFIGURE_ARGS+=	--with-rundir=${VARBASE}/run/freeswitch
CONFIGURE_ARGS+=	--with-logfiledir=${VARBASE}/log/freeswitch
CONFIGURE_ARGS+=	--with-dbdir=${VARBASE}/db/freeswitch
CONFIGURE_ARGS+=	--with-imagesdir=${PREFIX}/share/freeswitch/images
CONFIGURE_ARGS+=	--with-recordingsdir=${PREFIX}/freeswitch/recordings
CONFIGURE_ARGS+=	--with-modinstdir=${PREFIX}/freeswitch/modules
CONFIGURE_ARGS+=	--disable-libvpx
CONFIGURE_ARGS+=	--enable-srtp
CONFIGURE_ARGS+=	--enable-zrtp
CONFIGURE_ARGS+=	--enable-core-pgsql-support
CONFIGURE_ARGS+=	--enable-xmlrpc-c

REPLACE_PERL+=		support-d/utils/*
REPLACE_PERL+=		build/*
REPLACE_PERL+=		libs/xmlrpc-c/tools/binmode-rpc-kit/*
REPLACE_PERL+=		libs/apr/helpers/*
REPLACE_PERL+=		libs/sofia-sip/libsofia-sip-ua/tport/*
REPLACE_PERL+=		libs/*/*
REPLACE_PERL+=		libs/*/*/*
REPLACE_PERL+=		libs/libtpl-1.5/*/*/*/*
REPLACE_PERL+=		libs/libtpl-1.5/*/*/*
REPLACE_PERL+=		libs/libtpl-1.5/*/*
REPLACE_PERL+=		scripts/*
REPLACE_PERL+=		scripts/*/*
REPLACE_PERL+=		scripts/*/*/*
REPLACE_PERL+=		scripts/*/*/*/*
REPLACE_PERL+=		scripts/*/*/*/*/*/*
REPLACE_PERL+=		src/mod/*/*/*
REPLACE_PERL+=		src/mod/*/*/*/*
REPLACE_PERL+=		src/mod/*/*/*/*/*
REPLACE_PERL+=		docs/phrase/*

RCD_SCRIPTS=		freeswitch

INSTALLATION_DIRS+=	share/freeswitch/scripts
INSTALLATION_DIRS+=	share/freeswitch/grammar
INSTALLATION_DIRS+=	freeswitch/modules
INSTALLATION_DIRS+=	freeswitch/sounds
INSTALLATION_DIRS+=	freeswitch/recordings

.include "../../mk/bsd.prefs.mk"

FS_USER?=		freeswitch
FS_GROUP?=		freeswitch
PKG_USERS_VARS=		FS_USER
PKG_GROUPS_VARS=	FS_GROUP
PKG_GROUPS=		${FS_GROUP}
PKG_USERS=		${FS_USER}:${FS_GROUP}

PKG_GECOS.${FS_USER}=	FreeSWITCH
PKG_SHELL.${FS_USER}=	${NOLOGIN}

MAKE_DIRS+=		${VARBASE}/log/freeswitch
MAKE_DIRS+=		${VARBASE}/db/freeswitch
MAKE_DIRS_PERMS+=	${VARBASE}/log/freeswitch ${FS_USER} ${FS_GROUP} 0644
MAKE_DIRS_PERMS+=	${VARBASE}/db/freeswitch ${FS_USER} ${FS_GROUP} 0755
OWN_DIRS=		${PREFIX}/freeswitch
OWN_DIRS+=		${PREFIX}/share/freeswitch
OWN_DIRS_PERMS+=	${PREFIX}/freeswitch ${FS_USER} ${FS_GROUP} 0755
OWN_DIRS_PERMS+=	${PREFIX}/share/freeswitch ${FS_USER} ${FS_GROUP} 0755

PKG_SYSCONFSUBDIR=	freeswitch
PKG_SYSCONFDIR_PERMS=	${FS_USER} ${FS_GROUP} 0755

BUILDLINK_TRANSFORM+=	rm:-Werror

post-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libs/srtp/libsrtp.la ${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libs/spandsp/src/libspandsp.la ${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libs/tiff-4.0.2/libtiff/libtiff.la ${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libs/tiff-4.0.2/libtiff/libtiffxx.la ${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --finish ${PREFIX}/lib

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../devel/libmemcached/buildlink3.mk"
.include "../../lang/lua52/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../net/ldns/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
