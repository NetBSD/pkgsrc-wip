# $NetBSD: Makefile,v 1.1.1.1 2007/12/02 14:53:40 hoka_adam Exp $
#

DISTNAME=	efreet-0.0.3.006
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://download.enlightenment.org/snapshots/2007-08-26/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Interface Abstraction Library and Toolset

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS=	pkg-config

DEPENDS+=       ecore>=0.9.9.041:../../wip/ecore
.include        "../../wip/ecore/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
