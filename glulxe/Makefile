# $NetBSD: Makefile,v 1.10 2012/09/29 00:18:35 asau Exp $
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

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glulxe ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
