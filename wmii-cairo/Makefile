# $NetBSD: Makefile,v 1.4 2005/06/07 08:40:14 leonardschmidt Exp $
#

.include "../../wip/wmii/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-cairo-/}

COMMENT+=	(built with cairo support)

CONFLICTS=	wmii-[0-9]*

.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
