# $NetBSD: Makefile,v 1.6 2008/02/10 21:33:07 cheusov Exp $

.include "../../wip/pkg_update_summary/files/Makefile.version"

DISTNAME=	pkg_update_summary-${VERSION}
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://www.mova.org/~cheusov/
COMMENT=	Efficiently updates pkg_summary.gz file

USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		gzip:run
USE_LANGUAGES=		# empty

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${.CURDIR}/files
NO_CHECKSUM=	yes
NO_BUILD=	yes

MAKE_ENV+=	MAKEOBJDIR=${WRKDIR}
MAKE_ENV+=	MKCATPAGES=no

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
