# $NetBSD: Makefile,v 1.2 2004/10/22 21:05:48 johnrshannon Exp $

.include "../../wip/gettext-runtime/Makefile.common"

PKGNAME=		gettext-lib-${GETTEXT_VERSION}
SVR4_PKGNAME=		gttli

COMMENT=		Internationalized Message Handling Library (libintl)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
CONFIGURE_ARGS+=	--with-included-gettext

CONFIGURE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"
MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"

BUILD_DIRS=             ${WRKSRC}/gettext-runtime/intl

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CPPFLAGS+=		-D_INTL_REDIRECT_MACROS=1 -DSTATIC=static
.endif

TEST_TARGET=            check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
