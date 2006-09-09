# $NetBSD: Makefile,v 1.1 2006/09/09 15:28:16 cheusov Exp $
#

DISTNAME=		heirloom-sh-050706
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=heirloom/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		cheusov@tut.by
HOMEPAGE=		http://heirloom.sourceforge.net/
COMMENT=		Traditional Unix shell derived from OpenSolaris code

.include "../../mk/bsd.prefs.mk"

CFLAGS.Linux+=		-D_GNU_SOURCE -D_FILE_OFFSET_BITS=64L

PKGDOCDIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${PKGDOCDIR}

DOC_FILES=	CHANGES CALDERA.LICENSE OPENSOLARIS.LICENSE README

do-build:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		DESTDIR=${PREFIX:Q} -f makefile

do-install:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		DESTDIR=${PREFIX:Q} -f makefile install
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PKGDOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
