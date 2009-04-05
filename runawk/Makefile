# $NetBSD: Makefile,v 1.36 2009/04/05 14:51:08 cheusov Exp $
#

DISTNAME=	runawk-0.16.0
PKGREVISION=	1
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

.if ${OPSYS} == "SunOS"
MAKE_ENV+=		AWK_PROG=${AWK:Q}
.elif ${OPSYS} == "Interix"
MAKE_ENV+=		STDIN_FILENAME=-
.endif

PKGDOCDIR=		${PREFIX}/share/doc/${PKGBASE}

AUTO_MKDIRS=		yes

DOC_FILES=		README NEWS ChangeLog

MAKE_ENV+=		PREFIX=${PREFIX}
MAKE_ENV+=		MKCATPAGES=no
MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}

EGDIR=			${PREFIX}/share/examples/runawk

post-install:
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/"${i}" ${DESTDIR}${PKGDOCDIR}
.endfor
	cp -p ${WRKSRC}/examples/* ${DESTDIR}/${EGDIR}/

.include "../../mk/bsd.pkg.mk"
