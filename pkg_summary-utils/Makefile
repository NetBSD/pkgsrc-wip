# $NetBSD: Makefile,v 1.31 2009/08/10 19:37:06 cheusov Exp $

DISTNAME=	pkg_summary-utils-${VERSION}
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://www.mova.org/~cheusov/pub/pkg_summary-utils/
COMMENT=	Utilities for manipulating pkg_summary(5) files

LICENSE=	mit

DEPENDS+=	runawk>=0.16.0:../../wip/runawk
DEPENDS+=	awk-pkgsrc-dewey>=0.5.6:../../wip/awk-pkgsrc-dewey
DEPENDS+=	pipestatus-[0-9]*:../../wip/pipestatus
#DEPENDS+=	getopt-[0-9]*:../../misc/getopt

CONFLICTS+=	paexec<0.13.0nb1

CONFLICTS+=	pkg_src_summary-[0-9]*
CONFLICTS+=	pkg_cmp_summary-[0-9]*
CONFLICTS+=	pkg_src_update_summary-[0-9]*
CONFLICTS+=	pkg_update_summary-[0-9]*
CONFLICTS+=	pkg_summary4view-[0-9]*

.include "../../wip/pkg_summary-utils/files/Makefile.version"

TEST_TARGET=		test

NO_CHECKSUM=		yes

USE_BSD_MAKEFILE=	yes
USE_LANGUAGES=		#empty
USE_TOOLS+=		gzip:run

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${.CURDIR}/files

MAKE_ENV+=	MAKEOBJDIR=${WRKDIR}
MAKE_ENV+=	MKCATPAGES=no
MAKE_ENV+=	AWKMODDIR=${PREFIX}/share/runawk
MAKE_ENV+=	SH=${SH:Q}
MAKE_ENV+=	BMAKE=${MAKE:Q}

AUTO_MKDIRS=	yes

.include "../../mk/bsd.pkg.mk"
