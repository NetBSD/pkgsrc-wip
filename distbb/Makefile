# $NetBSD: Makefile,v 1.74 2010/12/20 15:15:39 cheusov Exp $
#

DISTNAME=	distbb-0.39.2
CATEGORIES=	pkgtools
MASTER_SITES=	http://mova.org/~cheusov/pub/distbb/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://mova.org/~cheusov/pub/distbb/
COMMENT=	DISTributed Bulk Build tool for pkgsrc
LICENSE=	2-clause-bsd

DEPENDS+=	pkg_summary-utils>=0.50beta2:../../wip/pkg_summary-utils
DEPENDS+=	paexec>=0.15.0:../../wip/paexec
DEPENDS+=	runawk>=1.1.0:../../wip/runawk
DEPENDS+=	pipestatus>=0.6.0:../../devel/pipestatus
DEPENDS+=	digest-[0-9]*:../../pkgtools/digest

BUILD_DEPENDS+=	mk-configure>=0.21:../../wip/mk-configure

USE_LANGUAGES=		# none

REPLACE_SH+=		distbb.in distbb_diff.in slave.in stage_*.in

PKG_DESTDIR_SUPPORT=	user-destdir

EGDIR=			${PREFIX}/share/examples/distbb
DOCDIR=			${PREFIX}/share/doc/distbb

CONF_FILES=		${EGDIR}/distbb.conf     ${PKG_SYSCONFDIR}/distbb.conf
CONF_FILES+=		${EGDIR}/distbb.local.mk ${PKG_SYSCONFDIR}/distbb.local.mk

DOCFILES=		README NEWS TODO

MAKE_FLAGS+=		EGDIR=${EGDIR}

AUTO_MKDIRS=		yes

post-install:
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"

MAKE_PROGRAM=		mkcmake
