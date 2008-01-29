# $NetBSD: Makefile,v 1.1 2008/01/29 19:31:46 cheusov Exp $

DISTNAME=	pkg_summary4view-0.8.0
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://www.mova.org/~cheusov/
COMMENT=	Builds summary information for source packages

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
USE_LANGUAGES=	# empty
NO_CHECKSUM=	YES
NO_BUILD=	YES

MAN1DIR=		${PREFIX}/${PKGMANDIR}/man1

INSTALLATION_DIRS=	bin ${MAN1DIR}

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/pkg_summary4view.sh \
		${DESTDIR}${PREFIX}/bin/pkg_summary4view
	${INSTALL_MAN} ${FILESDIR}/pkg_summary4view.1 ${DESTDIR}${MAN1DIR}

.include "../../mk/bsd.pkg.mk"
