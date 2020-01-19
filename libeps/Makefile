# $NetBSD: Makefile,v 1.1 2014/12/29 19:14:53 nros Exp $

DISTNAME=	eps-1.7
PKGNAME=	lib${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=epsinter7/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/epsinter7/
COMMENT=	API for parsing RFC2822 email messages
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes

pre-configure:
	${CP} ${FILESDIR}/CMakeLists.txt ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
