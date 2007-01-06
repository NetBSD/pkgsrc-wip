# $NetBSD: Makefile,v 1.1 2007/01/06 08:20:32 cheusov Exp $
#

DISTNAME=	netbsd-m4-3.1
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://mova.org/~cheusov/pub/netbsd-tools/
#${MASTER_SITE_SOURCEFORGE:=netbsd-tools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	# none
COMMENT=	NetBSD version of M4

MAKE_ENV+=	MKCATPAGES=no

post-patch:
	sed -e 's|m4|nbm4|g' ${WRKSRC}/m4.1 > ${WRKSRC}/nbm4.1

do-install:
	${INSTALL_MAN} ${WRKSRC}/nbm4.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/m4 ${PREFIX}/bin/nbm4

.include "../../mk/bsd.pkg.mk"
