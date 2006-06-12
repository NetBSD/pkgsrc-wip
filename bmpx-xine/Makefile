# $NetBSD: Makefile,v 1.2 2006/06/12 16:28:54 thomasklausner Exp $
#

.include "../../wip/bmpx/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-xine-/}
PKGREVISION=	1

COMMENT+=	(using xine)

CONFLICTS+=	bmpx-[0-9]*

.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
