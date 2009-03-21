# $NetBSD: Makefile,v 1.3 2009/03/21 12:26:29 jihbed Exp $
#

DISTNAME=		ltrace_0.3.36.orig
PKGNAME=		${DISTNAME:S/_/-/:S/.orig//}
CATEGORIES=		sysutils devel
MASTER_SITES=		${MASTER_SITE_DEBIAN:=pool/main/l/ltrace/}

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://ltrace.alioth.debian.org/
COMMENT=		Track runtime library calls in dynamically linked programs

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	Linux-*-*

WRKSRC=			${WRKDIR}/ltrace-0.3.36
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
# maybe following should be done in devel/libelf/buildlink3.mk instead
#CFLAGS+=		-I${BUILDLINK_PREFIX.libelf}/include/libelf
CPPFLAGS+=		-I${BUILDLINK_PREFIX.libelf}/include/libelf
#CPPFLAGS+=		-I${BUILDLINK_DIR}/include/libelf
#CFLAGS+=		-I${BUILDLINK_DIR}/include/libelf
# if this uses BUILDLINK_INCDIRS or CFLAGS for this. the build fails because
# it uses -I- which makes it ignore this include directory
#BUILDLINK_INCDIRS.libelf+=	include/libelf

INSTALLATION_DIRS+=	share/examples/ltrace

CONF_FILES=		${PREFIX}/share/examples/ltrace/ltrace.conf ${PKG_SYSCONFDIR}/ltrace.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/ltrace.conf ${PREFIX}/share/examples/ltrace

.include "../../devel/libelf/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
