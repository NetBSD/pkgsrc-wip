# $NetBSD: Makefile,v 1.3 2007/05/19 14:25:09 cheusov Exp $
#

DISTNAME=		heirloom-sh-050706
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=heirloom/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		cheusov@tut.by
HOMEPAGE=		http://heirloom.sourceforge.net/
COMMENT=		Traditional Unix shell derived from OpenSolaris code

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

CPPFLAGS.Linux+=	-D_GNU_SOURCE -D_FILE_OFFSET_BITS=64L

PKGDOCDIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${PKGDOCDIR}

DOC_FILES=	CHANGES CALDERA.LICENSE OPENSOLARIS.LICENSE README

MAKE_FILE=	makefile
MAKE_FLAGS+=	PREFIX=${PREFIX:Q}
MAKE_FLAGS+=	ROOT=${DESTDIR:Q}
MAKE_FLAGS+=	UCBINST=${INSTALL_DATA:Q}
MAKE_FLAGS+=	UCBINST_PROG=${INSTALL_PROGRAM:Q}
MAKE_FLAGS+=	STRIP=true

post-install:
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PKGDOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
