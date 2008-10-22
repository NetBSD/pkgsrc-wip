# $NetBSD: Makefile,v 1.31 2008/10/22 22:14:06 cheusov Exp $
#

DISTNAME=	runawk-0.14.3
CATEGORIES=	lang devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=runawk/} \
		http://mova.org/~cheusov/pub/runawk/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://sourceforge.net/projects/runawk
COMMENT=	Wrapper that impelements modules for AWK

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c
USE_BSD_MAKEFILE=	yes
TEST_TARGET=		test

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" #&& exists("/usr/bin/nawk")
MAKE_ENV+=		AWK_PROG=${AWK}
.endif

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
