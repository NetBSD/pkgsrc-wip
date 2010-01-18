# $NetBSD: Makefile,v 1.9 2010/01/18 09:38:33 thomasklausner Exp $
#

DISTNAME=		SPE-0.4.1.d-wx2.4.2.4.-bl2.28
PKGNAME=		spe-0.4.1
PKGREVISION=		1
CATEGORIES=		editors
MASTER_SITES=		http://projects.blender.org/download.php/47/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://stani.be/python/spe/blog/
COMMENT=		Python IDE with wxGlade GUI designer, auto-indentation and more

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
EXTRACT_CMD_OPTS.zip=	-qo

.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
