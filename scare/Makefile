# $NetBSD: Makefile,v 1.8 2012/12/12 10:44:38 thomasklausner Exp $
#

DISTNAME=		scare-1.3.3
CATEGORIES=		games
MASTER_SITES=		http://www.geocities.com/legion_if/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.geocities.com/legion_if/scare.html
COMMENT=		Interpreter for interactive fiction written in Adrift

BUILD_TARGET=		glkscare
MAKE_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR}

DOCDIR=			${PREFIX}/share/doc/scare

PKG_OPTIONS_VAR=PKG_OPTIONS.scare
.include "../../wip/glkloader/glk-options.mk"
.include "../../mk/bsd.options.mk"
.include "../../wip/glkloader/glk-depends.mk"

.include "../../devel/zlib/buildlink3.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glkscare ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/DEBUGGER ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/RUNNING ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
