# $NetBSD: Makefile,v 1.108 2019/01/09 19:12:14 adam Exp $

.include "Makefile.common"

BUILD_DEPENDS+=	docbook-xml-[0-9]*:../../textproc/docbook-xml
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=   ${PREFIX}/emul/netbsd32/
CONFIGURE_ARGS+=	--with-libxml-prefix=${BUILDLINK_PREFIX.compat32_libxml2}
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--with-html-subdir=libxslt
CFLAGS+=                -m32

PKGCONFIG_OVERRIDE=	libxslt.pc.in
PKGCONFIG_OVERRIDE+=	libexslt.pc.in
TEST_TARGET=		check

BUILDLINK_TRANSFORM.SunOS+=	opt:-Wl,./libxslt.syms:-Wl,./libxslt_solaris.syms

.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MIRIX-5*)
CPPFLAGS+=	-Dsocklen_t=int
.endif

BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.6.27

.include "../../wip/libgcrypt-32/buildlink3.mk"
.include "../../wip/libgpg-error-32/buildlink3.mk"
.include "../../wip/libxml2-32/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
