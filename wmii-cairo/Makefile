# $NetBSD: Makefile,v 1.3 2005/06/02 14:48:45 leonardschmidt Exp $
#

.include "../../wip/wmii/Makefile.common"

PKGNAME=	${DISTNAME:S/wmii/wmii-cairo/}

COMMENT+=	(built with cairo support)

CONFLICTS=	wmii-[0-9]*

.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
