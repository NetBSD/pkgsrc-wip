# $NetBSD: Makefile,v 1.8 2011/01/23 11:07:55 cheusov Exp $

DISTNAME=	pkg_conflicts-0.4.0
PKGREVISION=	1
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	# empty http://www.mova.org/~cheusov/pub/pkg_conflicts/
COMMENT=	Tools for automatic CONFLICTS detection

LICENSE=	mit

DEPENDS+=	runawk>=0.14.3:../../lang/runawk
DEPENDS+=	pkg_online-client>=0.6.0:../../wip/pkg_online-client
DEPENDS+=	pkg_summary-utils-[0-9]*:../../wip/pkg_summary-utils

USE_LANGUAGES=		#empty

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CHECKSUM=		yes
NO_BUILD=		yes

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_SCRIPT} ${.CURDIR}/files/pkg_* ${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
