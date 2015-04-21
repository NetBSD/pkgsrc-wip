# $NetBSD: Makefile,v 1.2 2015/04/21 07:21:55 krytarowski Exp $

DISTNAME=	lxqt-openssh-askpass-0.9.0
CATEGORIES=	x11
MASTER_SITES=	http://downloads.lxqt.org/lxqt/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxqt.org/
COMMENT=	Tool used with openssh to prompt the user for password
LICENSE=	gnu-lgpl-v2.1

EXTRACT_USING=	gtar

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../wip/liblxqt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
