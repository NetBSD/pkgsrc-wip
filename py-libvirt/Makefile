# $NetBSD: Makefile,v 1.32 2018/11/30 09:59:40 adam Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python//}
DISTNAME=	libvirt-python-5.8.0
CATEGORIES=	sysutils python
MASTER_SITES=	https://libvirt.org/sources/python/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libvirt.org/sources/python/
COMMENT=	libvirt python library
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config

.include "../../wip/libvirt/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
