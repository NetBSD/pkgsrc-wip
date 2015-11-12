# $NetBSD: Makefile,v 1.18 2012/11/23 22:44:43 othyro Exp $

DISTNAME=	dwerg-default-${DWERG_VERSION}
DWERG_VERSION=	0.8
PKGNAME=	gtk2-engines-dwerg-${DWERG_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=Manfred/}
GITHUB_PROJECT=	gtk-engines-dwerg
GITHUB_TAG=	03a9c43f2979cb4ccd59f5c12581c4a032ec246a

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Manfred/gtk-engines-dwerg
COMMENT=	Theme engine for GTK+ 2.x

USE_LIBTOOL=	YES
USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	YES

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
