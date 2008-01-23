# $NetBSD: Makefile,v 1.15 2008/01/23 20:02:54 cheusov Exp $
#

DISTNAME=	runawk-0.10.0
CATEGORIES=	lang devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=runawk/}

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://sourceforge.net/projects/runawk
COMMENT=	Wrapper that impelements modules for AWK

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c

PKGDOCDIR=		${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	share/runawk share/doc/runawk

DOC_FILES=		README NEWS ChangeLog

MAKE_ENV+=		PREFIX=${PREFIX}
MAKE_ENV+=		MKCATPAGES=no
MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}

post-install:
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/"${i}" ${DESTDIR}${PKGDOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
