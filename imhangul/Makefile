# $NetBSD: Makefile,v 1.5 2003/12/21 15:59:07 minskim Exp $
#

DISTNAME=	imhangul-0.9.9
CATEGORIES=	inputmethod
MASTER_SITES=	http://download.kldp.net/imhangul/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://imhangul.kldp.net/
COMMENT=	GTK+-2.0 Hangul Input Module

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
