# $NetBSD: Makefile,v 1.1.1.1 2005/10/04 12:31:11 leonardschmidt Exp $
#

.include "../../wip/bmpx/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-xine-/}

COMMENT+=	(using xine)

CONFLICTS+=	bmpx-[0-9]*

.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
