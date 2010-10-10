# $NetBSD: Makefile,v 1.69 2010/10/10 21:16:22 cheusov Exp $
#

DISTNAME=	distbb-0.38beta1
CATEGORIES=	pkgtools
MASTER_SITES=	http://mova.org/~cheusov/pub/distbb/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://mova.org/~cheusov/pub/distbb/
COMMENT=	DISTributed Bulk Build tool for pkgsrc

LICENSE=	mit

DEPENDS+=	pkg_summary-utils>=0.43.0:../../wip/pkg_summary-utils
DEPENDS+=	paexec>=0.15.0:../../wip/paexec
DEPENDS+=	runawk>=1.1.0:../../wip/runawk
DEPENDS+=	pipestatus>=0.6.0:../../devel/pipestatus
DEPENDS+=	digest-[0-9]*:../../pkgtools/digest

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
