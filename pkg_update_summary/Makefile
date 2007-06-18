# $NetBSD: Makefile,v 1.1 2007/06/18 21:44:17 cheusov Exp $

DISTNAME=	pkg_update_summary-0.3
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://mova.org/~cheusov
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
