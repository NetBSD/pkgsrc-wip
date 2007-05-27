# $NetBSD: Makefile,v 1.2 2007/05/27 06:51:50 bsadewitz Exp $

DISTNAME=	# empty
PKGNAME=	beryl-0.2.1
CATEGORIES=	meta-pkgs
MASTER_SITES=	http://www.beryl-project.org/0.2.1/
DISTFILES=	# empty

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://www.beryl-project.org/
COMMENT=	Beryl compositing window manager

DEPENDS+=	beryl-core>=0.2.1:../../wip/beryl-core
DEPENDS+=	beryl-settings-bindings>=0.2.1:../../wip/beryl-settings-bindings
DEPENDS+=	beryl-settings>=0.2.1:../../wip/beryl-settings
DEPENDS+=	beryl-settings-simple>=0.2.1:../../wip/beryl-settings-simple
DEPENDS+=	beryl-plugins>=0.2.1:../../wip/beryl-plugins
DEPENDS+=	beryl-manager>=0.2.1:../../wip/beryl-manager
DEPENDS+=	emerald>=0.2.1:../../wip/emerald

NO_BUILD=		yes
NO_CHECKSUM=		yes
NO_MTREE=		yes
NO_CONFIGURE=		yes

do-install:

.include "../../mk/bsd.pkg.mk"
