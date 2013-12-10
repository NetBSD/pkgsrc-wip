# $NetBSD: Makefile,v 1.2 2013/12/10 13:19:26 noud4 Exp $

DISTNAME=	PHP_CodeSniffer-1.4.7
CATEGORIES=	devel

MAINTAINER=	noud4@home.nl
HOMEPAGE= 	http://www.squizlabs.com/php-codesniffer
COMMENT=	Detects PHP, JavaScript and CSS violations of coding standards
LICENSE=	modified-bsd

USE_TOOLS+=	gtar

do-extract:
	cd ${WRKDIR} && gtar xfpz ${DISTDIR}/pear/${DISTNAME}${EXTRACT_SUFX}

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
