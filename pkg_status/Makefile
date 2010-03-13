# $NetBSD: Makefile,v 1.2 2010/03/13 18:00:44 cheusov Exp $

DISTNAME=	pkg_status-0.5
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	# empty
COMMENT=	Shows status of installed packages

LICENSE=	mit

DEPENDS+=	pipestatus-[0-9]*:../../devel/pipestatus
DEPENDS+=	pkg_summary-utils-[0-9]*:../../wip/pkg_summary-utils

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS+=	bin

NO_CHECKSUM=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${.CURDIR}/files/pkg_status ${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
