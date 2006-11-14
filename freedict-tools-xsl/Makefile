# $NetBSD: Makefile,v 1.2 2006/11/14 19:20:32 shattered Exp $
#

DISTNAME=	freedict-tools-0.1-1.noarch
PKGNAME=	freedict-tools-xsl-0.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freedict/}
EXTRACT_SUFX=	.rpm

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://www.freedict.org/
COMMENT=	XSL files from FreeDict tools

USE_TOOLS+=	install pax #rpm2cpio cpio
NO_BUILD=	yes

BUILD_DEPENDS+= rpm2cpio-[0-9]*:../../converters/rpm2cpio

.include "../../mk/bsd.prefs.mk"

CPIO?=		cpio

DOCDIR=		${PREFIX}/share/doc/freedict-tools-xsl
XSLDIR=		${PREFIX}/share/freedict-tools-xsl

INSTALLATION_DIRS+=	${BINDIR} ${DOCDIR} ${XSLDIR} ${XSLDIR}/inc

DOCFILES=	COPYING README

do-extract:
	${MKDIR} ${WRKSRC} && \
	cd ${WRKSRC} && \
	${PREFIX}/bin/rpm2cpio.pl \
		${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} >temp.cpio && \
	${CPIO} -i --make-directories < temp.cpio

do-install:
	cd ${WRKSRC}/usr/src/freedict/tools/xsl && \
	${PAX} -rw -pm . ${XSLDIR}
	cd ${WRKSRC}/usr/share/doc/packages/freedict-tools && \
	${INSTALL_DATA} ${DOCFILES} ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
