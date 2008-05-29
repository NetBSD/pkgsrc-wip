# $NetBSD: Makefile,v 1.25 2008/05/29 21:26:42 cheusov Exp $
#

DISTNAME=	runawk-0.12.1
PKGREVISION=	1
CATEGORIES=	lang devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=runawk/}

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://sourceforge.net/projects/runawk
COMMENT=	Wrapper that impelements modules for AWK

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c
USE_BSD_MAKEFILE=	yes
TEST_TARGET=		test

PKGDOCDIR=		${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS+=	share/runawk share/doc/runawk
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

DOC_FILES=		README NEWS ChangeLog

MAKE_ENV+=		PREFIX=${PREFIX}
MAKE_ENV+=		MKCATPAGES=no
MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}

post-install:
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/"${i}" ${DESTDIR}${PKGDOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
