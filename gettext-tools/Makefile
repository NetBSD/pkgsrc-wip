# $NetBSD: Makefile,v 1.5 2005/04/11 21:12:26 tvierling Exp $

.include "../../wip/gettext-runtime/Makefile.common"

PKGNAME=	gettext-tools-${GETTEXT_VERSION}
WRKSRC=		${WRKDIR}/${DISTNAME}/gettext-tools

COMMENT=	Tools and documentation for internationalized development

DISTINFO_FILE=	${.CURDIR}/../../wip/gettext-runtime/distinfo

# should make this more specific?
CONFLICTS=	gettext-[0-9]*
#CONFLICTS+=	gettext-lib-[0-9]*
CONFLICTS+=	gettext-m4-[0-9]*

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

INFO_FILES=		gettext.info

# not tested yet
TEST_TARGET=		check

.include "../../wip/gettext-runtime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
