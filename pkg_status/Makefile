# $NetBSD: Makefile,v 1.8 2010/03/17 10:10:32 cheusov Exp $

DISTNAME=	pkg_status-0.7
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

USE_BSD_MAKEFILE=	yes
NO_CHECKSUM=		yes

WRKSRC=			${.CURDIR}/files

MAKE_ENV+=		PKG_INFO_CMD=${PKG_INFO:Q}
MAKE_ENV+=		PACKAGES=${PACKAGES}
MAKE_ENV+=		MKCATPAGES=no

MAKE_ENV+=		MAKEOBJDIR=${WRKDIR}

DOCDIR=			share/doc/pkg_status

INSTALLATION_DIRS+=	bin ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
