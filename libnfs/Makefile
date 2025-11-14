# $NetBSD$

DISTNAME=	libnfs-6.0.2
CATEGORIES=	net filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=sahlberg/}
GITHUB_TAG=	refs/tags/${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sahlberg/libnfs
COMMENT=	NFS client library
# LGPL applies to the library itself, and GPL applies to utilities.
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v3

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}

USE_TOOLS+=	autoconf automake autoreconf pkg-config
USE_LIBTOOL=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-utils
CONFIGURE_ARGS+=	--enable-pthread
CONFIGURE_ARGS+=	--disable-werror # -Werror is only good for development.

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "Linux"
# GnuTLS is of course platform-independent but the way libnfs uses it is
# Linux-dependent.
.  include "../../security/gnutls/buildlink3.mk"
.endif

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && ${SH} ./bootstrap

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
