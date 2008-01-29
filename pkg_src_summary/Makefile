# $NetBSD: Makefile,v 1.3 2008/01/29 19:07:40 cheusov Exp $

DISTNAME=	pkg_src_summary-0.4.1
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
	${INSTALL_SCRIPT} ${FILESDIR}/pkg_src_summary.sh \
		${DESTDIR}${PREFIX}/bin/pkg_src_summary
	${INSTALL_MAN} ${FILESDIR}/pkg_src_summary.1 ${DESTDIR}${MAN1DIR}

.include "../../mk/bsd.pkg.mk"
