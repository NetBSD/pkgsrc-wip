# $NetBSD: Makefile,v 1.2 2004/08/17 18:26:27 tvierling Exp $

.include "Makefile.common"

# should this be called gettext-base ?
PKGNAME=	gettext-runtime-${GETTEXT_VERSION}
WRKSRC=		${WRKDIR}/${DISTNAME}/gettext-runtime

COMMENT=	Runtime libraries and programs for internationalized programs

# should make this more specific?
CONFLICTS=	gettext-[0-9]*

.include "../../mk/bsd.prefs.mk"

# maybe should be !Linux
.if ${OPSYS} == "NetBSD"
CONFLICTS+=		gettext-lib-[0-9]*
LIBTOOL_LA_FILES+=	lib/libintl.la
.endif

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_LA_FILES+=	lib/libasprintf.la
CONFIGURE_ARGS+=	--mandir=${PREFIX}/man

INFO_FILES=		autosprintf.info

# not tested yet
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
