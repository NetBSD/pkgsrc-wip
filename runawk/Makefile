# $NetBSD: Makefile,v 1.4 2007/10/21 15:34:58 cheusov Exp $
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

MAKE_FLAGS+=		PREFIX=${PREFIX:Q}
MAKE_FLAGS+=		DESTDIR=${DESTDIR:Q}
MAKE_FLAGS+=		INSTALL="${INSTALL_PROGRAM}"

post-install:
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/"${i}" ${DESTDIR}${PKGDOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
