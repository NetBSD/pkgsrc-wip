# $NetBSD: Makefile,v 1.6 2012/11/17 18:31:46 outpaddling Exp $

DISTNAME=	libctl-3.2.1
CATEGORIES=	devel
MASTER_SITES=	http://ab-initio.mit.edu/libctl/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://ab-initio.mit.edu/libctl/
COMMENT=	Guile-based flexible control file library for scientific simulations
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

USE_LANGUAGES=	c fortran77

INSTALLATION_DIRS=	share/doc/libctl

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${PREFIX}/share/doc/libctl/
	cd ${WRKSRC} && ${INSTALL_DATA} \
		AUTHORS ChangeLog COPYING COPYRIGHT INSTALL NEWS README TODO \
		${DESTDIR}${PREFIX}/share/doc/libctl/

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
