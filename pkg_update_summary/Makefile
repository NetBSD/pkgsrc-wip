# $NetBSD: Makefile,v 1.3 2007/07/15 18:33:16 shattered Exp $

DISTNAME=	pkg_update_summary-0.4
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://www.mova.org/~cheusov/
COMMENT=	Efficiently updates pkg_summary.gz file

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
USE_LANGUAGES=	# empty
USE_TOOLS+=	gzip:run
NO_CHECKSUM=	YES
NO_BUILD=	YES

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/pkg_update_summary.sh ${PREFIX}/sbin/pkg_update_summary

.include "../../mk/bsd.pkg.mk"
