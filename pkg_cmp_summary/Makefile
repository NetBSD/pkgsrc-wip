# $NetBSD: Makefile,v 1.1 2008/02/10 19:06:08 cheusov Exp $

DISTNAME=	pkg_cmp_summary-0.2.0
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://www.mova.org/~cheusov/
COMMENT=	Compares two package summary files (pkg_summary.txt format)

USE_BSD_MAKEFILE=	yes

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${.CURDIR}/files
USE_LANGUAGES=	# empty
NO_CHECKSUM=	YES
NO_BUILD=	YES

MAKE_ENV+=	MAKEOBJDIR=${WRKDIR}
MAKE_ENV+=	MKCATPAGES=no

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
