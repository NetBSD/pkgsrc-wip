# $NetBSD: Makefile,v 1.15 2008/06/15 13:42:36 cheusov Exp $

DISTNAME=	pkg_summary-utils-${VERSION}
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://www.mova.org/~cheusov/pub/pkg_summary-utils/
COMMENT=	Utilities for manipulating pkg_summary(5) files

DEPENDS+=	runawk>=0.12.1:../../wip/runawk
DEPENDS+=	paexec>=0.9.0:../../wip/paexec
DEPENDS+=	awk-pkgsrc-dewey>=0.5.6:../../wip/awk-pkgsrc-dewey
DEPENDS+=	pipestatus-[0-9]*:../../wip/pipestatus

CONFLICTS+=	pkg_src_summary-[0-9]*
CONFLICTS+=	pkg_cmp_summary-[0-9]*
CONFLICTS+=	pkg_src_update_summary-[0-9]*
CONFLICTS+=	pkg_update_summary-[0-9]*
CONFLICTS+=	pkg_summary4view-[0-9]*

.include "../../wip/pkg_summary-utils/files/Makefile.version"

USE_BSD_MAKEFILE=	yes
USE_LANGUAGES=		#empty
USE_TOOLS+=		gzip:run

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${.CURDIR}/files
NO_CHECKSUM=	yes
NO_BUILD=	yes

MAN1DIR=	${PKGMANDIR}/man1

MAKE_ENV+=	MAKEOBJDIR=${WRKDIR}
MAKE_ENV+=	MKCATPAGES=no
MAKE_ENV+=	AWKMODDIR=${PREFIX}/share/runawk

INSTALLATION_DIRS+=	bin ${MAN1DIR} share/doc/pkg_summary-utils share/runawk

.include "../../mk/bsd.pkg.mk"
