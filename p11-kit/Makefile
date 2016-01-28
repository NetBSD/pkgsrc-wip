# $NetBSD: Makefile,v 1.2 2012/10/23 18:16:39 asau Exp $
#

DISTNAME=		p11-kit-0.23.2
CATEGORIES=		security
MASTER_SITES=		http://p11-glue.freedesktop.org/releases/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://p11-glue.freedesktop.org/
COMMENT=		PKCS11 module manager
LICENSE=		modified-bsd

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	p11-kit/p11-kit-1.pc.in

MAKE_FLAGS+=		exampledir=${PREFIX}/share/examples/p11-kit
PKG_SYSCONFSUBDIR=	pkcs11
CONF_FILES+=		share/examples/p11-kit/pkcs11.conf.example \
			${PKG_SYSCONFDIR}/pkcs11.conf

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
CFLAGS+=	-D_NETBSD_SOURCE
.endif

BUILDLINK_API_DEPENDS.libtasn1+=	libtasn1>=2.3
.include "../../security/libtasn1/buildlink3.mk"
BUILDLINK_API_DEPENDS.libffi+=		libffi>=3.0.0
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
