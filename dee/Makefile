# $NetBSD: Makefile,v 1.3 2012/09/28 21:24:33 asau Exp $
#

DISTNAME=	dee-0.5.22
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/dee/0.5/0.5.22/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://launchpad.net/dee
COMMENT=	Model to synchronize mutiple instances over DBus
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3 # probably

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	dee-1.0.pc.in

PY_PATCHPLIST=	yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
