# $NetBSD: Makefile,v 1.2 2005/10/17 15:34:55 ghen Exp $

DISTNAME=	wsbasic-1_2_4
PKGNAME=	${DISTNAME:S/_/./}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wsbasic/}

MAINTAINER=	geert.hendrickx@ua.ac.be
HOMEPAGE=	http://wsbasic.sourceforge.net/
COMMENT=	Simple BASIC interpreter

SUBST_CLASSES+=			interpreter
SUBST_STAGE.interpreter=	pre-install
SUBST_FILES.interpreter=	scripts/*.b
SUBST_SED.interpreter=		-e 's,^\#!\.\./wsbasic,\#!${PREFIX}/bin/wsbasic,'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wsbasic ${PREFIX}/bin/
	${INSTALL_SCRIPT_DIR} ${PREFIX}/share/wsbasic
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/*.b ${PREFIX}/share/wsbasic/
	${INSTALL_DATA} ${WRKSRC}/scripts/*.txt ${PREFIX}/share/wsbasic/

.include "../../mk/bsd.pkg.mk"
