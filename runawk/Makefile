# $NetBSD: Makefile,v 1.7 2007/10/21 16:02:35 cheusov Exp $
#

DISTNAME=	runawk-0.8.0
CATEGORIES=	lang devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=runawk/}

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://sourceforge.net/projects/runawk
COMMENT=	Wrapper that impelements modules for AWK

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c

PKGDOCDIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${PKGDOCDIR} bin

DOC_FILES=		README NEWS ChangeLog

MAKE_FLAGS+=		PREFIX=${PREFIX:Q}
MAKE_FLAGS+=		DESTDIR=${DESTDIR:Q}
MAKE_FLAGS+=		INSTALL="${INSTALL_PROGRAM}"
MAKE_FLAGS+=		WARFLAGS=

post-install:
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/"${i}" ${DESTDIR}${PKGDOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
