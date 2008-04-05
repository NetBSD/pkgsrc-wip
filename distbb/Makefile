# $NetBSD: Makefile,v 1.13 2008/04/05 11:07:43 cheusov Exp $
#

DISTNAME=	distbb-0.6.0
CATEGORIES=	pkgtools
MASTER_SITES=	http://mova.org/~cheusov/pub/distbb/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://mova.org/~cheusov/pub/distbb/
COMMENT=	DISTributed Bulk Build framework for pkgsrc

DEPENDS+=	pkg_summary-utils>=0.4.0:../../wip/pkg_summary-utils
DEPENDS+=	paexec>=0.8.0:../../wip/paexec
DEPENDS+=	rsync-[0-9]*:../../net/rsync
DEPENDS+=	shlock-[0-9]*:../../pkgtools/shlock
DEPENDS+=	netbsd-uuencode>=4.0nb1:../../wip/netbsd-uuencode

USE_LANGUAGES=		# none
USE_BSD_MAKEFILE=	yes

EGDIR=			${PREFIX}/share/examples/distbb
MAKE_FLAGS+=		EGDIR=${EGDIR}

INSTALLATION_DIRS+=	bin ${EGDIR} libexec/distbb

.include "../../mk/bsd.pkg.mk"
