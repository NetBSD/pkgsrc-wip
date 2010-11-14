# $NetBSD: Makefile,v 1.43 2010/11/14 01:04:30 cheusov Exp $

DISTNAME=	pkg_summary-utils-${VERSION}
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://www.mova.org/~cheusov/pub/pkg_summary-utils/
COMMENT=	Utilities for manipulating pkg_summary(5) files
LICENSE=	2-clause-bsd

DEPENDS+=	runawk>=1.1.0:../../wip/runawk
DEPENDS+=	pipestatus-[0-9]*:../../devel/pipestatus

BUILD_DEPENDS+=	mk-configure>=0.20.0:../../wip/mk-configure

CONFLICTS+=	paexec<0.15.0
CONFLICTS+=	awk-pkgsrc-dewey-[0-9]*
CONFLICTS+=	pkg_src_summary-[0-9]*
CONFLICTS+=	pkg_cmp_summary-[0-9]*
CONFLICTS+=	pkg_src_update_summary-[0-9]*
CONFLICTS+=	pkg_update_summary-[0-9]*
CONFLICTS+=	pkg_summary4view-[0-9]*

TEST_TARGET=		test

NO_CHECKSUM=		yes

USE_LANGUAGES=		#empty
USE_TOOLS+=		gzip:run

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${.CURDIR}/files

EGDIR=		${PREFIX}/share/examples/pkg_summary-utils

CONF_FILES=	${EGDIR}/pkg_digger.conf ${PKG_SYSCONFDIR}/pkg_digger.conf

MAKE_ENV+=	MAKEOBJDIR=${WRKDIR}
MAKE_ENV+=	AWKMODDIR=${PREFIX}/share/runawk
MAKE_ENV+=	EGDIR=${EGDIR}
MAKE_ENV+=	SH=${SH:Q}
MAKE_ENV+=	BMAKE=${MAKE:Q}
MAKE_ENV+=	DISTDIR=${DISTDIR}
MAKE_ENV+=	PKGSRCDIR=${PKGSRCDIR}
MAKE_ENV+=	PKG_SUFX=${PKG_SUFX}
MAKE_ENV+=	PKG_INFO_CMD=${PKG_INFO:Q}

AUTO_MKDIRS=	yes

.include "../../wip/pkg_summary-utils/files/version.mk"
.include "../../mk/bsd.pkg.mk"

MAKE_PROGRAM=	mkcmake
