# $NetBSD: Makefile,v 1.14 2010/12/28 15:55:02 cheusov Exp $

DISTNAME=	pkg_status-${VERSION}
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	# empty
COMMENT=	Shows status of installed packages

LICENSE=	2-clause-bsd

DEPENDS+=	pipestatus-[0-9]*:../../devel/pipestatus
DEPENDS+=	pkg_summary-utils>=0.50beta4:../../wip/pkg_summary-utils

PKG_DESTDIR_SUPPORT=	user-destdir

USE_BSD_MAKEFILE=	yes
NO_CHECKSUM=		yes

WRKSRC=			${.CURDIR}/files

MAKE_ENV+=		PKG_INFO_CMD=${PKG_INFO:Q}
MAKE_ENV+=		PKG_DELETE_CMD=${PKG_DELETE:Q}
MAKE_ENV+=		PKG_ADMIN_CMD=${PKG_ADMIN:Q}
MAKE_ENV+=		PACKAGES=${PACKAGES}
MAKE_ENV+=		MKCATPAGES=no

MAKE_ENV+=		MAKEOBJDIR=${WRKDIR}

DOCDIR=			share/doc/pkg_status

INSTALLATION_DIRS+=	bin ${DOCDIR}

.include "../../wip/pkg_status/files/version.mk"
.include "../../mk/bsd.pkg.mk"
