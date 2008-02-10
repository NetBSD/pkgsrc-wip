# $NetBSD: Makefile,v 1.6 2008/02/10 21:51:12 cheusov Exp $

.include "../../wip/pkg_src_summary/files/Makefile.version"

DISTNAME=	pkg_src_summary-${VERSION}

CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://www.mova.org/~cheusov/
COMMENT=	Builds summary information for source packages

USE_BSD_MAKEFILE=	yes
USE_LANGUAGES=	# empty

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${.CURDIR}/files
NO_CHECKSUM=	yes
NO_BUILD=	yes

MAKE_ENV+=	MAKEOBJDIR=${WRKDIR}
MAKE_ENV+=	MKCATPAGES=no

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
