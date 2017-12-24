# $NetBSD: Makefile,v 1.3 2015/05/30 01:23:41 krytarowski Exp $

DISTNAME=	lxqt-openssh-askpass-0.10.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxde/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxqt.org/
COMMENT=	Tool used with openssh to prompt the user for password
LICENSE=	gnu-lgpl-v2.1

EXTRACT_USING=	gtar

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../wip/liblxqt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
