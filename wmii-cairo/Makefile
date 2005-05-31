# $NetBSD: Makefile,v 1.1.1.1 2005/05/31 12:53:28 leonardschmidt Exp $
#

.include "../../wip/wmii/Makefile.common"

PKGNAME=	${DISTNAME:S/wmii/wmii-cairo/}

COMMENT+=	(built with cairo support)

CONFLICTS=	wmii-[0-9]*

.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
