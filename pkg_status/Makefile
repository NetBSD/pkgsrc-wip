# $NetBSD: Makefile,v 1.5 2010/03/14 09:24:01 cheusov Exp $

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

WRKSRC=		${WRKDIR}

do-build:
	sed -e 's,@PKG_INFO_CMD@,${PKG_INFO},' \
	    -e 's,@PACKAGES@,${PACKAGES},' \
	    ${.CURDIR}/files/pkg_status.in > ${WRKSRC}/pkg_status

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_status ${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
