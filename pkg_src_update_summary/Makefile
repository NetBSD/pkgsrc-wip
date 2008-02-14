# $NetBSD: Makefile,v 1.2 2008/02/14 21:03:34 cheusov Exp $

DISTNAME=	pkg_src_update_summary-${VERSION}
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://www.mova.org/~cheusov/
COMMENT=	Builds summary information for source packages

DEPENDS+=	pipestatus-[0-9]*:../../wip/pipestatus
DEPENDS+=	pkg_src_summary-[0-9]*:../../wip/pkg_src_summary
DEPENDS+=	pkg_cmp_summary-[0-9]*:../../wip/pkg_cmp_summary

.include "../../wip/pkg_src_update_summary/files/Makefile.version"

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
