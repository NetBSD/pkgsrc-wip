# $NetBSD: Makefile,v 1.4 2012/10/03 09:10:44 asau Exp $

DISTNAME=		ltrace-0.7.3
CATEGORIES=		sysutils devel
MASTER_SITES=		${MASTER_SITE_DEBIAN:=pool/main/l/ltrace/}
DISTFILES=		${DISTNAME:S,-,_,}.orig.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://ltrace.alioth.debian.org/
COMMENT=		Track runtime library calls in dynamically linked programs
LICENSE=		gnu-gpl-v2

# see configure.ac, keyword host-os
ONLY_FOR_PLATFORM=	Linux-*-*

CHECK_PORTABILITY_SKIP=	testsuite/run-my-tests.sh
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/ltrace
CPPFLAGS+=		-I${BUILDLINK_PREFIX.libelf}/include/libelf
AUTO_MKDIRS=		yes

CONF_FILES=		${PREFIX}/share/examples/ltrace/ltrace.conf ${PKG_SYSCONFDIR}/ltrace.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/ltrace.conf ${PREFIX}/share/examples/ltrace

.include "../../devel/libelf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
