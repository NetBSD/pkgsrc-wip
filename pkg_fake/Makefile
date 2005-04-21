# $NetBSD: Makefile,v 1.1.1.1 2005/04/21 14:54:41 poppnk Exp $

DISTNAME=	pkg_fake-20050421
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pancake@phreaker.net
COMMENT=	pkgsrc tool to create and manage fake packages

NO_CONFIGURE=	yes
NO_CHECKSUM=	yes
NO_BUILD=	yes

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_fake ${PREFIX}/sbin/pkg_fake

.include "../../mk/bsd.pkg.mk"
