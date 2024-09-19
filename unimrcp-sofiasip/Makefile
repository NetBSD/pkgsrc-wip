# $NetBSD$

DISTNAME=	sofia-sip-${VERSION}
VERSION=	1.12.11-204-g6ff5f3f
CATEGORIES=	devel
MASTER_SITES=	https://sites.google.com/a/unimrcp.org/unimrcp/dependencies/

MAINTAINER=	angelmadames@gmail.com
HOMEPAGE=	https://sites.google.com/a/unimrcp.org/unimrcp/dependencies/
COMMENT=	Patched SOFIA-SIP version for UniMRCP
LICENSE=	apache-2.0

HAS_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config autoconf aclocal automake awk:run
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--prefix=${PREFIX}/unimrcp/sofia-sip
CONFIGURE_ARGS+=	--with-glib=no
CONFIGURE_ARGS+=	--without-doxygen

PKGCONFIG_OVERRIDE+=	packages/sofia-sip-ua-glib.pc.in
PKGCONFIG_OVERRIDE+=	packages/sofia-sip-ua.pc.in

# Taken from devel/sofia-sip
SUBST_CLASSES+=		awk
SUBST_FILES.awk+=	libsofia-sip-ua/msg/msg_parser.awk
SUBST_FILES.awk+=	libsofia-sip-ua/su/tag_dll.awk
SUBST_STAGE.awk=	pre-configure
SUBST_SED.awk=		-e "s,/usr/bin/env *awk,${AWK},"
SUBST_MESSAGE.awk=	Fixing path to awk.

pre-configure:
	set -x; cd ${WRKSRC}; autoreconf -fiv
	${MAKE} ${PATCH}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
