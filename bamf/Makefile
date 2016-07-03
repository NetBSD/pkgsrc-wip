# $NetBSD: Makefile,v 1.13 2015/06/06 18:48:10 krytarowski Exp $
#

DISTNAME=	bamf-0.5.1
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://launchpad.net/bamf/0.5/0.5.1/+download/

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	http://launchpad.net/bamf/
COMMENT=	DBus daemon and C wrapper library of applications matching framework
LICENSE=	gnu-lgpl-v3

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

DEPENDS+=	${PYPKGPREFIX}-libxml2-[0-9]*:../../textproc/py-libxml2
DEPENDS+=	${PYPKGPREFIX}-libxslt-[0-9]*:../../textproc/py-libxslt

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libwnck3/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
