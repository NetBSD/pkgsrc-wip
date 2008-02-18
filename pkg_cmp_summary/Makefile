# $NetBSD: Makefile,v 1.4 2008/02/18 09:21:34 cheusov Exp $

DISTNAME=	pkg_cmp_summary-${VERSION}
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://www.mova.org/~cheusov/
COMMENT=	Compares two package summary files (pkg_summary.txt format)

DEPENDS+=	runawk-[0-9]*:../../wip/runawk
DEPENDS+=	awk-pkgsrc-dewey-[0-9]*:../../wip/awk-pkgsrc-dewey

.include "../../wip/pkg_cmp_summary/files/Makefile.version"

USE_BSD_MAKEFILE=	yes

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${.CURDIR}/files
USE_LANGUAGES=	# empty
NO_CHECKSUM=	yes
NO_BUILD=	yes

MAN1DIR=	${PKGMANDIR}/man1
MAKE_ENV+=	MAKEOBJDIR=${WRKDIR}
MAKE_ENV+=	MKCATPAGES=no

INSTALLATION_DIRS+=	bin ${MAN1DIR}

.include "../../mk/bsd.pkg.mk"
