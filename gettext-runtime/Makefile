# $NetBSD: Makefile,v 1.1.1.1 2004/03/06 07:20:11 jeremy-c-reed Exp $

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
CONFLICTS+=	gettext-lib-[0-9]*
.endif

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--mandir=${PREFIX}/man

INFO_FILES=		autosprintf.info

# not tested yet
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
