# $NetBSD: Makefile,v 1.4 2003/09/17 23:49:45 minskim Exp $
#

DISTNAME=		nabi-0.6
CATEGORIES=		korean inputmethod
MASTER_SITES=		http://download.kldp.net/nabi/

MAINTAINER=		minskim@bawi.org
HOMEPAGE=		http://nabi.kldp.net/
COMMENT=		X Input Method for Korean

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
