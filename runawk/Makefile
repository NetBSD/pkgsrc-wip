# $NetBSD: Makefile,v 1.3 2007/10/21 15:28:55 cheusov Exp $
#

DISTNAME=	runawk-0.8.0
CATEGORIES=	lang devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=runawk/}

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://sourceforge.net/projects/runawk
COMMENT=	Wrapper that impelements modules for AWK

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LANGUAGES=	c

PKGDOCDIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${PKGDOCDIR} bin

DOC_FILES=		README NEWS ChangeLog

MAKE_FLAGS+=		ROOT=${PREFIX:Q}
MAKE_FLAGS+=		DESTDIR=${DESTDIR:Q}
MAKE_FLAGS+=		WARFLAGS=
MAKE_FLAGS+=		STDIN_FILENAME=/dev/stdin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/runawk ${DESTDIR}${PREFIX}/bin/
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/"${i}" ${DESTDIR}${PKGDOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
