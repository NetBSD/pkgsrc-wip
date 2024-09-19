# $NetBSD: Makefile,v 1.6 2014/11/25 12:28:53 thomasklausner Exp $

DISTNAME=	dee-1.2.7
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/dee/1.0/1.2.7/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/dee
COMMENT=	Model to synchronize mutiple instances over DBus
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	dee-1.0.pc.in

PY_PATCHPLIST=	yes

.include "options.mk"

.include "../../lang/vala/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
