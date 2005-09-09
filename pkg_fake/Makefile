# $NetBSD: Makefile,v 1.2 2005/09/09 00:16:25 poppnk Exp $

DISTNAME=	pkg_fake-0.1
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pancake@phreaker.net
COMMENT=	pkgsrc tool to create and manage fake packages

NO_CONFIGURE=	yes
NO_CHECKSUM=	yes
NO_BUILD=	yes

DEPENDS+=  pkg_alternatives>=1.3:../../pkgtools/pkg_alternatives/

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_fake ${PREFIX}/sbin/pkg_fake

.include "../../mk/bsd.pkg.mk"
