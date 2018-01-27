# $NetBSD: Makefile,v 1.1 2013/09/11 03:36:33 phonohawk Exp $
#

DISTNAME=	pymigemo-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://www.atzm.org/etc/files/pymigemo/

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://www.atzm.org/etc/pymigemo.html
COMMENT=	Python bindings for C/Migemo
LICENSE=	2-clause-bsd

# textproc/cmigemo lacks buildlink3.mk for some reason.
BUILDLINK_TREE+=		cmigemo
BUILDLINK_API_DEPENDS.cmigemo+=	cmigemo-[0-9]*
BUILDLINK_PKGSRCDIR.cmigemo?=	../../textproc/cmigemo
BUILDLINK_TREE+=		-cmigemo

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
