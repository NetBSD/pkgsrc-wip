# $NetBSD: Makefile,v 1.50 2008/12/26 23:44:37 cheusov Exp $
#

DISTNAME=	distbb-0.26.0
CATEGORIES=	pkgtools
MASTER_SITES=	http://mova.org/~cheusov/pub/distbb/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://mova.org/~cheusov/pub/distbb/
COMMENT=	DISTributed Bulk Build tool for pkgsrc

DEPENDS+=	pkg_summary-utils>=0.22.0:../../wip/pkg_summary-utils
DEPENDS+=	paexec>=0.12.1:../../wip/paexec
DEPENDS+=	runawk>=0.14.3:../../wip/runawk

USE_LANGUAGES=		# none
USE_BSD_MAKEFILE=	yes

REPLACE_SH+=		distbb.in distbb_diff.in slave.in stage_*.in

PKG_DESTDIR_SUPPORT=	user-destdir

EGDIR=			${PREFIX}/share/examples/distbb
DOCDIR=			${PREFIX}/share/doc/distbb

CONF_FILES=		${EGDIR}/distbb.conf     ${PKG_SYSCONFDIR}/distbb.conf
CONF_FILES+=		${EGDIR}/distbb.local.mk ${PKG_SYSCONFDIR}/distbb.local.mk

DOCFILES=		README NEWS TODO

MAKE_FLAGS+=		EGDIR=${EGDIR}

INSTALLATION_DIRS+=	bin ${EGDIR} ${DOCDIR} libexec/distbb share/distbb

post-install:
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
