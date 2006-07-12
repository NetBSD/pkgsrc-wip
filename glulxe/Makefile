# $NetBSD: Makefile,v 1.9 2006/07/12 23:18:22 dillo Exp $
#

DISTNAME=	glulxe-035
PKGNAME=	glulxe-0.3.5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_IFARCHIVE:=programming/glulx/interpreters/glulxe/}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.eblong.com/zarf/glulx/index.html
COMMENT=	Interpreter for Glulx text adventures

WRKSRC=		${WRKDIR}/glulxe
MAKE_ENV+=	BUILDLINK_DIR=${BUILDLINK_DIR:Q}

PKG_OPTIONS_VAR=PKG_OPTIONS.glulxe
.include "../../wip/glkloader/glk-options.mk"
.include "../../mk/bsd.options.mk"
.include "../../wip/glkloader/glk-depends.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glulxe ${LOCALBASE}/bin

.include "../../mk/bsd.pkg.mk"
