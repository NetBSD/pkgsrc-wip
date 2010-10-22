# $NetBSD: Makefile,v 1.49 2010/10/22 22:53:46 cheusov Exp $
#

DISTNAME=	runawk-1.2.0
CATEGORIES=	lang devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=runawk/} \
		http://mova.org/~cheusov/pub/runawk/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://sourceforge.net/projects/runawk
COMMENT=	AWK wrapper that provides support for modules

LICENSE=		mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c
TEST_TARGET=		test

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	AWK_PROG=${AWK:Q}
.endif

MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}

PKGDOCDIR=		${PREFIX}/share/doc/runawk
EGDIR=			${PREFIX}/share/examples/runawk

AUTO_MKDIRS=		yes

DOC_FILES=		README NEWS ChangeLog TODO

post-install:
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/"${i}" ${DESTDIR}${PKGDOCDIR}
.endfor
	cp -p ${WRKSRC}/examples/* ${DESTDIR}/${EGDIR}/

.include "../../mk/bsd.pkg.mk"

MAKE_PROGRAM=		mkcmake
