# $NetBSD: Makefile,v 1.4 2013/01/20 12:46:22 othyro Exp $
#

DISTNAME=	dee-1.0.14
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/dee/1.0/1.0.14/+download/
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://launchpad.net/dee
COMMENT=	Model to synchronize mutiple instances over DBus
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
CONFIGURE_ENV+=	VALA_API_GEN=${BUILDLINK_PREFIX.vala}/bin/vapigen-0.18

PKGCONFIG_OVERRIDE+=	dee-1.0.pc.in

PY_PATCHPLIST=	yes

.include "options.mk"

.include "../../lang/vala018/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
