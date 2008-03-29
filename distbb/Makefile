# $NetBSD: Makefile,v 1.8 2008/03/29 00:05:42 cheusov Exp $
#

DISTNAME=	distbb-0.1.6
CATEGORIES=	pkgtools
MASTER_SITES=	http://mova.org/~cheusov/pub/distbb/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://mova.org/~cheusov/pub/distbb/
COMMENT=	DISTributed Bulk Build framework for pkgsrc

DEPENDS+=	pkg_src_summary>=0.8.3:../../wip/pkg_src_summary
DEPENDS+=	awk-pkgsrc-dewey>=0.5.2:../../wip/awk-pkgsrc-dewey
DEPENDS+=	pkg_cmp_summary>=0.6.2:../../wip/pkg_cmp_summary
DEPENDS+=	pkg_src_update_summary>=0.5.0:../../wip/pkg_src_update_summary
DEPENDS+=	pkg_update_summary>=0.8.0:../../wip/pkg_update_summary
DEPENDS+=	paexec>=0.8.0:../../wip/paexec
DEPENDS+=	rsync-[0-9]*:../../net/rsync
DEPENDS+=	nail-[0-9]*:../../mail/nail
DEPENDS+=	shlock-[0-9]*:../../pkgtools/shlock

USE_LANGUAGES=		# none
USE_BSD_MAKEFILE=	yes

INSTALLATION_DIRS+=	bin share/distbb libexec/distbb

.include "../../mk/bsd.pkg.mk"
