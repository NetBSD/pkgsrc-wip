# $NetBSD: Makefile,v 1.6 2004/08/17 18:26:52 tvierling Exp $
#

DISTNAME=	GNUnet-0.5.4a
CATEGORIES=	x11
MASTER_SITES=	http://www.ovmj.org/GNUnet/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.ovmj.org/GNUnet/
COMMENT=	Framework for secure p2p networking

BUILD_USES_MSGFMT=	yes

USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
LIBTOOL_LA_FILES+=	lib/libgnunetafs_blocks.la
LIBTOOL_LA_FILES+=	lib/libgnunetafs_database.la
LIBTOOL_LA_FILES+=	lib/libgnunetafs_database_directory.la
LIBTOOL_LA_FILES+=	lib/libgnunetafs_database_gdbm.la
LIBTOOL_LA_FILES+=	lib/libgnunetafs_decoding.la
LIBTOOL_LA_FILES+=	lib/libgnunetafs_delete.la
LIBTOOL_LA_FILES+=	lib/libgnunetafs_encoding.la
LIBTOOL_LA_FILES+=	lib/libgnunetafs_policy.la
LIBTOOL_LA_FILES+=	lib/libgnunetafs_protocol.la
LIBTOOL_LA_FILES+=	lib/libgnunetafs_search.la
LIBTOOL_LA_FILES+=	lib/libgnunetafs_util.la
LIBTOOL_LA_FILES+=	lib/libgnunetchat_protocol.la
LIBTOOL_LA_FILES+=	lib/libgnunetcommon.la
LIBTOOL_LA_FILES+=	lib/libgnunettbench_protocol.la
LIBTOOL_LA_FILES+=	lib/libgnunettracekit_protocol.la
LIBTOOL_LA_FILES+=	lib/libgnunettransport_http.la
LIBTOOL_LA_FILES+=	lib/libgnunettransport_smtp.la
LIBTOOL_LA_FILES+=	lib/libgnunettransport_tcp.la
LIBTOOL_LA_FILES+=	lib/libgnunettransport_udp.la
LIBTOOL_LA_FILES+=	lib/libgnunetutil.la
LIBTOOL_LA_FILES+=	lib/libltdl.la

PTHREAD_OPTS=	require

CONFIGURE_ARGS+=        --without-gtk
CONFIGURE_ARGS+=        --with-crypto
CONFIGURE_ARGS+=	--with-gdbm=${BUILDLINK_PREFIX.gdbm}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

LDFLAGS+=	-lpthread -lintl

.include "../../mk/bsd.prefs.mk"
BUILD_DEFS+=	USE_INET6

.if defined(USE_INET6)
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
