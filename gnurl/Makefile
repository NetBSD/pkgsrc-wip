# $NetBSD$

DISTNAME=	gnurl-7.63.0
CATEGORIES=	www
MASTER_SITES=   ${MASTER_SITE_GNU:=gnunet/}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ng0@n0.is
HOMEPAGE=	https://gnunet.org/gnurl
COMMENT=	Client that groks URLs
# not completely, but near enough
LICENSE=	mit

# list it into IPv6-ready packages
BUILD_DEFS+=	IPV6_READY

USE_TOOLS+=		nroff perl pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-ca-path=${SSLCERTS}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
PKGCONFIG_OVERRIDE=	libgnurl.pc.in

INSTALLATION_DIRS=	share/doc/gnurl

.include "../../mk/bsd.prefs.mk"

TEST_TARGET=		check

# This fork of curl implies a hardcoded set of configurations,
# therefore keep the the following configure arguments intact!

CONFIGURE_ARGS+= --disable-ntml-wb

# This might be configurable.
CONFIGURE_ARGS+= --enable-ipv6

# We want GnuTLS with Dane.
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gnutls/libgnutls-config.mk"
CONFIGURE_ARGS+= --with-gnutls

.include "../../devel/libidn2/buildlink3.mk"
CONFIGURE_ARGS+= --with-libidn2

CONFIGURE_ARGS+= --without-gssapi

.include "options.mk"

post-install:
.for f in MANUAL TheArtOfHttpScripting FAQ
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DESTDIR}${PREFIX}/share/doc/gnurl/
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
