# $NetBSD: Makefile,v 1.1.1.1 2004/03/28 00:35:27 mpasternak Exp $
#

DISTNAME=		SPE-0.4.1.d-wx2.4.2.4.-bl2.28
PKGNAME=		spe-0.4.1
CATEGORIES=		editors
MASTER_SITES=		http://projects.blender.org/download.php/47/
EXTRACT_SUFX=		.zip

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://spe.pycs.net/
COMMENT=		Python IDE with wxGlade GUI designer, auto-indentation and more

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
EXTRACT_CMD_OPTS.zip=	-aqo

.include "../../x11/py-wxWindows/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
