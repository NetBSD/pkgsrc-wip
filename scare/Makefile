# $NetBSD: Makefile,v 1.6 2006/07/12 23:18:22 dillo Exp $
#

DISTNAME=		scare-1.3.3
CATEGORIES=		games
MASTER_SITES=		http://www.geocities.com/legion_if/
EXTRACT_SUFX=		.zip

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://www.geocities.com/legion_if/scare.html
COMMENT=		Interpreter for interactive fiction written in Adrift

BUILD_TARGET=		glkscare
MAKE_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR:Q}

DOCDIR=			${LOCALBASE}/share/doc/scare

PKG_OPTIONS_VAR=PKG_OPTIONS.scare
.include "../../wip/glkloader/glk-options.mk"
.include "../../mk/bsd.options.mk"
.include "../../wip/glkloader/glk-depends.mk"

.include "../../devel/zlib/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glkscare ${LOCALBASE}/bin
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/DEBUGGER ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/RUNNING ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
