# $NetBSD: Makefile,v 1.1 2010/02/13 23:53:05 pettai Exp $
#

DISTNAME=	pylibpcap-0.6.2
PKGNAME=	${PYPKGPREFIX}-pylibpcap-0.6.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pylibpcap/}

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://pylibpcap.sourceforge.net/
COMMENT=	Python module for the libpcap packet capture library
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= yes

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
