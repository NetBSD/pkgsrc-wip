# $NetBSD: Makefile,v 1.1.1.1 2003/07/31 07:19:09 minskim Exp $
#

DISTNAME=	imhangul-0.9.6
CATEGORIES=	inputmethod
MASTER_SITES=	http://download.kldp.net/imhangul/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://imhangul.kldp.net/
COMMENT=	GTK+-2.0 Hangul Input Module

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
