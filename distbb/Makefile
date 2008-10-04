# $NetBSD: Makefile,v 1.37 2008/10/04 20:23:08 cheusov Exp $
#

DISTNAME=	distbb-0.20.1
PKGREVISION=	1
CATEGORIES=	pkgtools
MASTER_SITES=	http://mova.org/~cheusov/pub/distbb/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://mova.org/~cheusov/pub/distbb/
COMMENT=	DISTributed Bulk Build tool for pkgsrc

DEPENDS+=	pkg_summary-utils>=0.17.2:../../wip/pkg_summary-utils
DEPENDS+=	paexec>=0.10.0:../../wip/paexec
DEPENDS+=	rsync-[0-9]*:../../net/rsync
DEPENDS+=	runawk>=0.13.0:../../wip/runawk

USE_LANGUAGES=		# none
USE_BSD_MAKEFILE=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

EGDIR=			${PREFIX}/share/examples/distbb
DOCDIR=			${PREFIX}/share/doc/distbb

DOCFILES=		README NEWS TODO

MAKE_FLAGS+=		EGDIR=${EGDIR}

INSTALLATION_DIRS+=	bin ${EGDIR} ${DOCDIR} libexec/distbb share/distbb

post-install:
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
