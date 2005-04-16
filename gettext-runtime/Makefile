# $NetBSD: Makefile,v 1.5 2005/04/16 23:49:59 jeremy-c-reed Exp $

.include "Makefile.common"

PKGNAME=	gettext-runtime-${GETTEXT_VERSION}
WRKSRC=		${WRKDIR}/${DISTNAME}/gettext-runtime

COMMENT=	Runtime libraries and programs for internationalized programs

# should make this more specific?
CONFLICTS=	gettext-[0-9]*

.include "../../mk/bsd.prefs.mk"

# maybe should be !Linux
.if ${OPSYS} == "NetBSD"
CONFLICTS+=		gettext-lib-[0-9]*
.endif

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

INFO_FILES=		autosprintf.info

# not tested yet
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
