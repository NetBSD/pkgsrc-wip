# $NetBSD: Makefile,v 1.1.1.1 2004/10/22 19:04:22 johnrshannon Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1998/08/09 15:13:33 kuriyama Exp
#

DISTNAME=		gettext-0.14.1
PKGNAME=		gettext-lib-0.14.1
SVR4_PKGNAME=		gttli
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=gettext/}

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gettext/gettext.html
COMMENT=		Internationalized Message Handling Library (libintl)

CONFLICTS=		gettext<=0.14.01

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
