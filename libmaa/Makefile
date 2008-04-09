# $NetBSD: Makefile,v 1.13 2008/04/09 09:18:34 cheusov Exp $

.include "../../wip/dict-server/Makefile.common"

PKGNAME=	libmaa-1.0.1
PKGREVISION=	1
CATEGORIES=	devel
COMMENT=	Provides a few data structures and helpful functions

CONFIGURE_DIRS=		libmaa
BUILD_DIRS=		libmaa

BUILD_TARGET=		lib

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

PKGDOCDIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${PKGDOCDIR} lib include

EXTRA_DOC_FILES=	COPYING.LIB README doc/libmaa.600dpi.ps

post-install:
	set -e; \
	for i in ${EXTRA_DOC_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/libmaa/"$${i}" ${DESTDIR}${PKGDOCDIR}; \
	done

PATCHDIR=	${.CURDIR}/../../wip/dict-server/patches
DISTINFO_FILE=	${.CURDIR}/../../wip/dict-server/distinfo

.include "../../mk/bsd.pkg.mk"
