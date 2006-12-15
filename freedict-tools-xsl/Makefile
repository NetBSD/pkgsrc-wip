# $NetBSD: Makefile,v 1.3 2006/12/15 20:13:10 cheusov Exp $
#

DISTNAME=	freedict-tools-0.2
PKGNAME=	freedict-tools-xsl-0.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freedict/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://www.freedict.org/
COMMENT=	XSL files from FreeDict tools

USE_TOOLS+=	install pax
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/tools

.include "../../mk/bsd.prefs.mk"

DOCDIR=		${PREFIX}/share/doc/freedict-tools-xsl
XSLDIR=		${PREFIX}/share/freedict-tools-xsl

INSTALLATION_DIRS+=	${DOCDIR} ${XSLDIR} ${XSLDIR}/inc

DOCFILES=	COPYING README

do-install:
	cd ${WRKSRC} && \
	${INSTALL_DATA} ${DOCFILES} ${DOCDIR} && \
	cd ${WRKSRC}/xsl && \
	pax -rw -pm . ${XSLDIR}

.include "../../mk/bsd.pkg.mk"
