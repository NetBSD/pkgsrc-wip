# $NetBSD: Makefile,v 1.20 2014/08/03 19:48:22 cheusov Exp $
#

DISTNAME=	distbb-${_GIT_PKGVERSION}
PKGREVISION=
CATEGORIES=	pkgtools

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://mova.org/~cheusov/pub/distbb/
COMMENT=	DISTributed Bulk Build tool for pkgsrc
LICENSE=	2-clause-bsd

GIT_REPOSITORIES=	distbb
GIT_REPO.distbb=	https://github.com/cheusov/distbb.git
.include "../../wip/mk/git-package.mk"

DEPENDS+=	pkg_summary-utils>=0.69.1:../../pkgtools/pkg_summary-utils
DEPENDS+=	paexec>=1.1.6:../../parallel/paexec
DEPENDS+=	runawk>=1.1.0:../../lang/runawk
DEPENDS+=	digest-[0-9]*:../../pkgtools/digest

TOOL_DEPENDS+=	mk-configure>=0.21:../../devel/mk-configure

WRKSRC=		${WRKDIR}/distbb

USE_LANGUAGES=		# none

REPLACE_SH+=		distbb.in distbb_diff.in slave.in stage_*.in

REPLACE_INTERPRETER+=	runawk
REPLACE.runawk.old=	/usr/bin/env runawk
REPLACE.runawk.new=	${PREFIX}/bin/runawk
REPLACE_FILES.runawk=	gen_weights.in gen_queue.in pkg_summary2build_deps.in \
			distbb_grep.in

EGDIR=			${PREFIX}/share/examples/distbb
DOCDIR=		${PREFIX}/share/doc/distbb

CONF_FILES=		${EGDIR}/distbb.conf     ${PKG_SYSCONFDIR}/distbb.conf
CONF_FILES+=		${EGDIR}/distbb.local.mk ${PKG_SYSCONFDIR}/distbb.local.mk

MAKE_FLAGS+=		EGDIR=${EGDIR}
MAKE_ENV+=		DOC_FILES='LICENSE NEWS TODO TUTORIAL.pod'
MAKE_ENV+=		VERSION=${_GIT_PKGVERSION}

post-install:
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor

.include "../../devel/mk-configure/mk-c.mk"
.include "../../mk/bsd.pkg.mk"
