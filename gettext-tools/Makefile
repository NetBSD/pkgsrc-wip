# $NetBSD: Makefile,v 1.1.1.1 2004/03/06 07:51:24 jeremy-c-reed Exp $

.include "../../wip/gettext-runtime/Makefile.common"

PKGNAME=	gettext-tools-${GETTEXT_VERSION}
WRKSRC=		${WRKDIR}/${DISTNAME}/gettext-tools

COMMENT=	Tools and documentation for internationalized development

DISTINFO_FILE=	${.CURDIR}/../../wip/gettext-runtime/distinfo

# should make this more specific?
CONFLICTS=	gettext-[0-9]*
#CONFLICTS+=	gettext-lib-[0-9]*
CONFLICTS+=	gettext-m4-[0-9]*

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--mandir=${PREFIX}/man

INFO_FILES=		gettext.info

# not tested yet
TEST_TARGET=		check

.include "../../wip/gettext-runtime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
